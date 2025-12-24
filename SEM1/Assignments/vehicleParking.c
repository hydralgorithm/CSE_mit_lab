#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*Setting up the constant values of certain for all the functions*/
#define FLOORS 3
#define SLOTS  10
#define MAX (FLOORS * SLOTS)


/* Convert a string to uppercase for case-insensitive matching */
void toUpperStr(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = (char)toupper((unsigned char)s[i]);
    }
}

/* Convert HH MM into minutes since midnight (00:00) */
int toMinutes(int hh, int mm) {
    if (hh < 0) hh = 0; if (hh > 23) hh = 23;
    if (mm < 0) mm = 0; if (mm > 59) mm = 59;
    return hh * 60 + mm;
}

/* Compute billed hours from start and end minutes (round up) */
int roundedHours(int startMins, int endMins) {
    int mins = endMins - startMins;
    if (mins <= 0) return 0;           /* same-time or invalid -> 0 hours */
    return (mins + 59) / 60;           /* ceil(mins/60.0) without math.h */
}

/* Fare by type (1=bike, 2=car, 3=truck) times hours */
int calcFare(int type, int hours) {
    int rate = 0;
    if (type == 1) rate = 20;
    else if (type == 2) rate = 50;
    else if (type == 3) rate = 100;
    else rate = 0;
    return rate * hours;
}

int main() {
    /* ------------------------- DATA STRUCTURES ------------------------- */

    /* 2D array: -1 means empty slot; otherwise stores index into vehicles[] */
    int slots[FLOORS][SLOTS];
    for (int i = 0; i < FLOORS; i++)
        for (int j = 0; j < SLOTS; j++)
            slots[i][j] = -1;

    /* Structure to hold vehicle details (Strings + time + location) */
    struct Vehicle {
        int active;         /* 1 = currently parked, 0 = exited */
        char number[16];    /* vehicle number plate (string) */
        int type;           /* 1=Bike, 2=Car, 3=Truck */
        int entryMins;      /* entry time in minutes from 00:00 */
        int floor;          /* 0..FLOORS-1 where parked */
        int slot;           /* 0..SLOTS-1 where parked */
    };

    /* Array of structures (MAX = capacity) */
    struct Vehicle vehicles[MAX];
    for (int i = 0; i < MAX; i++) vehicles[i].active = 0;

    /* ------------------------- ACCOUNTING STATE ------------------------ */
    int occupied = 0;           /* current occupied slots */
    int servedCount = 0;        /* vehicles that exited with billing */
    float revenue = 0.0f;       /* total revenue */

    /* ----------------------------- MENU LOOP --------------------------- */
    int choice;
    do {
        printf("\n=== Smart Vehicle Parking ===\n");
        printf("1. Park Vehicle\n");
        printf("2. Exit Vehicle (Bill)\n");
        printf("3. Find Vehicle by Number\n");
        printf("4. Show Slot Map\n");
        printf("5. End-of-Day Report\n");
        printf("6. Exit Program\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) { while (getchar()!='\n'); continue; }

        if (choice == 1) {
            /* ------------------------ Park Vehicle ------------------------ */
            if (occupied == FLOORS * SLOTS) {
                printf("Parking Full.\n");
                continue;
            }

            char number[16];
            int type, hh, mm;

            printf("Enter Vehicle Number (e.g., KA01AB1234): ");
            if (scanf("%15s", number) != 1) { while (getchar()!='\n'); continue; }
            toUpperStr(number); /* string operation */

            printf("Type (1=Bike, 2=Car, 3=Truck): ");
            if (scanf("%d", &type) != 1 || type < 1 || type > 3) {
                printf("Invalid type.\n");
                while (getchar()!='\n');
                continue;
            }

            printf("Entry Time (HH MM, 24-hr): ");
            if (scanf("%d %d", &hh, &mm) != 2 || hh < 0 || hh > 23 || mm < 0 || mm > 59) {
                printf("Invalid time.\n");
                while (getchar()!='\n');
                continue;
            }
            int entryMins = toMinutes(hh, mm);

            /* find first free slot in the 2D array */
            int f = -1, s = -1;
            for (int i = 0; i < FLOORS && f == -1; i++) {
                for (int j = 0; j < SLOTS; j++) {
                    if (slots[i][j] == -1) { f = i; s = j; break; }
                }
            }
            if (f == -1) { /* should not happen because we checked 'full' above */
                printf("Parking Full.\n");
                continue;
            }

            /* find a free vehicle record */
            int idx = -1;
            for (int i = 0; i < MAX; i++) {
                if (vehicles[i].active == 0) { idx = i; break; }
            }
            if (idx == -1) { /* defensive check */
                printf("Internal capacity reached.\n");
                continue;
            }

            /* fill the vehicle structure */
            vehicles[idx].active = 1;
            strncpy(vehicles[idx].number, number, 15);
            vehicles[idx].number[15] = '\0';
            vehicles[idx].type = type;
            vehicles[idx].entryMins = entryMins;
            vehicles[idx].floor = f;
            vehicles[idx].slot = s;

            /* link slot to structure index and update occupancy */
            slots[f][s] = idx;
            occupied++;

            printf("Parked at Floor %d, Slot %d.\n", f + 1, s + 1);
        }
        else if (choice == 2) {
            /* --------------------- Exit Vehicle (Bill) --------------------- */
            char query[16];
            int hh, mm;

            printf("Enter Vehicle Number to exit: ");
            if (scanf("%15s", query) != 1) { while (getchar()!='\n'); continue; }
            toUpperStr(query);

            /* search active vehicle by number (strings + loops) */
            int idx = -1;
            for (int i = 0; i < MAX; i++) {
                if (vehicles[i].active == 1 && strcmp(vehicles[i].number, query) == 0) {
                    idx = i; break;
                }
            }
            if (idx == -1) {
                printf("Vehicle not found or already exited.\n");
                continue;
            }

            printf("Exit Time (HH MM): ");
            if (scanf("%d %d", &hh, &mm) != 2 || hh < 0 || hh > 23 || mm < 0 || mm > 59) {
                printf("Invalid time.\n");
                while (getchar()!='\n');
                continue;
            }
            int exitMins = toMinutes(hh, mm);
            if (exitMins < vehicles[idx].entryMins) {
                printf("Exit time cannot be earlier than entry time (same day rule).\n");
                continue;
            }

            int hours = roundedHours(vehicles[idx].entryMins, exitMins);
            int fare  = calcFare(vehicles[idx].type, hours);

            /* clear 2D slot and close the vehicle record */
            int f = vehicles[idx].floor;
            int s = vehicles[idx].slot;
            slots[f][s] = -1;
            vehicles[idx].active = 0;

            occupied--;
            servedCount++;
            revenue += (float)fare;

            printf("Billed %d hour(s). Fare: ₹%d | Freed Floor %d, Slot %d.\n",
                   hours, fare, f + 1, s + 1);
        }
        else if (choice == 3) {
            /* --------------------- Find Vehicle by Number ------------------ */
            char query[16];
            printf("Enter Vehicle Number to find: ");
            if (scanf("%15s", query) != 1) { while (getchar()!='\n'); continue; }
            toUpperStr(query);

            int found = 0;
            for (int i = 0; i < MAX; i++) {
                if (vehicles[i].active == 1 && strcmp(vehicles[i].number, query) == 0) {
                    printf("Found: Floor %d, Slot %d | Type %d\n",
                           vehicles[i].floor + 1, vehicles[i].slot + 1, vehicles[i].type);
                    found = 1; break;
                }
            }
            if (!found) printf("Vehicle not found in the parking lot.\n");
        }
        else if (choice == 4) {
            /* ------------------------- Show Slot Map ----------------------- */
            for (int i = 0; i < FLOORS; i++) {
                printf("Floor %d: ", i + 1);
                for (int j = 0; j < SLOTS; j++) {
                    printf("%c ", (slots[i][j] == -1) ? '_' : 'X');
                }
                printf("\n");
            }
            float occ = (occupied * 100.0f) / (FLOORS * SLOTS);
            printf("Occupied: %d/%d (%.2f%%)\n",
                   occupied, FLOORS * SLOTS, occ);
        }
        else if (choice == 5) {
            /* ----------------------- End-of-Day Report --------------------- */
            float usage = (occupied * 100.0f) / (FLOORS * SLOTS);
            printf("\n=== End-of-Day Report ===\n");
            printf("Capacity        : %d slots\n", FLOORS * SLOTS);
            printf("Currently used  : %d (%.2f%%)\n", occupied, usage);
            printf("Vehicles served : %d\n", servedCount);
            printf("Total revenue   : ₹%.2f\n", revenue);
            printf("==========================\n");
        }
        else if (choice == 6) {
            printf("Exiting. Goodbye!\n");
        }
        else {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}