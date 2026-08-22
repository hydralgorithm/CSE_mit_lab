#include <stdio.h>
int strLen(char *s) {
    int len = 0;
    while (*(s + len) != '\0')
        len++;
    return len;
}
void strConcat(char *s1, char *s2, char *res) {
    int i = 0, j = 0;
    while (*(s1 + i) != '\0') {
        *(res + i) = *(s1 + i);
        i++;
    }
    while (*(s2 + j) != '\0') {
        *(res + i) = *(s2 + j);
        i++;
        j++;
    }
    *(res + i) = '\0';
}
int strCmp(char *s1, char *s2) {
    int i = 0;
    while (*(s1 + i) != '\0' && *(s2 + i) != '\0') {
        if (*(s1 + i) != *(s2 + i))
            return *(s1 + i) - *(s2 + i);
        i++;
    }
    return *(s1 + i) - *(s2 + i);
}
void insertSub(char *s, char *sub, int pos, char *res) {
    int i = 0, j = 0, k = 0;
    while (i < pos)
        *(res + k++) = *(s + i++);
    while (*(sub + j) != '\0')
        *(res + k++) = *(sub + j++);
    while (*(s + i) != '\0')
        *(res + k++) = *(s + i++);
    *(res + k) = '\0';
}
void deleteSub(char *s, int pos, int len, char *res) {
    int i = 0, k = 0;
    while (i < pos)
        *(res + k++) = *(s + i++);
    i += len;
    while (*(s + i) != '\0')
        *(res + k++) = *(s + i++);
    *(res + k) = '\0';
}
int main() {
    char s1[100], s2[100], res[200], sub[50];
    int pos, len, ch;
    printf("Enter string: ");
    scanf("%s", s1);
    printf("1.Length 2.Concat 3.Compare 4.Insert sub 5.Delete sub\nChoice: ");
    scanf("%d", &ch);
    if (ch == 1) {
        printf("Length: %d\n", strLen(s1));
    } else if (ch == 2) {
        printf("Enter s2: ");
        scanf("%s", s2);
        strConcat(s1, s2, res);
        printf("Result: %s\n", res);
    } else if (ch == 3) {
        printf("Enter s2: ");
        scanf("%s", s2);
        int c = strCmp(s1, s2);
        if (c == 0) printf("Equal\n");
        else if (c < 0) printf("s1 < s2\n");
        else printf("s1 > s2\n");
    } else if (ch == 4) {
        printf("Enter sub and pos: ");
        scanf("%s %d", sub, &pos);
        insertSub(s1, sub, pos, res);
        printf("Result: %s\n", res);
    } else if (ch == 5) {
        printf("Enter pos and len: ");
        scanf("%d %d", &pos, &len);
        deleteSub(s1, pos, len, res);
        printf("Result: %s\n", res);
    }
    return 0;
}
