#include <stdio.h>
#define MAX 10

// Array representation: index = power, value = coefficient
void multiplyPoly(int poly1[], int deg1, int poly2[], int deg2, int result[]) {
    int resultDeg = deg1 + deg2;

    // Initialize result array to 0
    for (int i = 0; i <= resultDeg; i++)
        result[i] = 0;

    // Multiply each term of poly1 with each term of poly2
    for (int i = 0; i <= deg1; i++) {
        for (int j = 0; j <= deg2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}

void displayPoly(int poly[], int deg) {
    for (int i = deg; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d", poly[i], i);
            if (i != 0) printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    // P1(x) = 5x^3 + 4x^2 + 2x + 6  -> index = power
    int poly1[MAX] = {6, 2, 4, 5};   // poly1[0]=6, poly1[1]=2, poly1[2]=4, poly1[3]=5
    int deg1 = 3;

    // P2(x) = 3x^3 + 2x^2 + 5x + 1
    int poly2[MAX] = {1, 5, 2, 3};   // poly2[0]=1, poly2[1]=5, poly2[2]=2, poly2[3]=3
    int deg2 = 3;

    int result[MAX] = {0};

    printf("P1(x): ");
    displayPoly(poly1, deg1);
    printf("P2(x): ");
    displayPoly(poly2, deg2);

    multiplyPoly(poly1, deg1, poly2, deg2, result);

    printf("Product P1(x) * P2(x): ");
    displayPoly(result, deg1 + deg2);

    return 0;
}