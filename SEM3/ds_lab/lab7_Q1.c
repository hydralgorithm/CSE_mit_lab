#include <stdio.h>
#include <string.h>
#define MAX 100
char stk[MAX];
int top = -1;
void push(char c) { stk[++top] = c; }
char pop() { return stk[top--]; }
int isEmpty() { return top == -1; }
void palindrome() {
    char s[MAX];
    int i, len, flag = 1;
    printf("Enter string: ");
    scanf("%s", s);
    len = strlen(s);
    top = -1;
    for (i = 0; i < len; i++) push(s[i]);
    for (i = 0; i < len; i++) {
        if (s[i] != pop()) { flag = 0; break; }
    }
    printf(flag ? "Palindrome\n" : "Not palindrome\n");
}
void matchParens() {
    char s[MAX];
    int i, flag = 1;
    printf("Enter expression: ");
    scanf("%s", s);
    top = -1;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') push(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (isEmpty()) { flag = 0; break; }
            char t = pop();
            if ((s[i] == ')' && t != '(') || (s[i] == ']' && t != '[') || (s[i] == '}' && t != '{'))
                { flag = 0; break; }
        }
    }
    if (!isEmpty()) flag = 0;
    printf(flag ? "Balanced\n" : "Not balanced\n");
}
int main() {
    int ch;
    while (1) {
        printf("\n1.Palindrome 2.Parentheses check 3.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) palindrome();
        else if (ch == 2) matchParens();
        else if (ch == 3) break;
        else printf("Invalid\n");
    }
    return 0;
}
