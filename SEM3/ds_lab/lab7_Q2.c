#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct CNode {
    char data;
    struct CNode *next;
};
struct CNode *ctop = NULL;
void cpush(char c) {
    struct CNode *n = (struct CNode *)malloc(sizeof(struct CNode));
    n->data = c; n->next = ctop; ctop = n;
}
char cpop() {
    if (!ctop) return '\0';
    char c = ctop->data;
    struct CNode *t = ctop; ctop = ctop->next; free(t);
    return c;
}
char cpeek() { return ctop ? ctop->data : '\0'; }
int cisEmpty() { return ctop == NULL; }
int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}
int isOp(char c) { return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'; }
void infixToPostfix() {
    char expr[100], res[100];
    int i = 0, j = 0;
    printf("Enter infix: ");
    scanf("%s", expr);
    ctop = NULL;
    while (expr[i] != '\0') {
        char c = expr[i];
        if (isalnum(c)) { res[j++] = c; }
        else if (c == '(') { cpush(c); }
        else if (c == ')') {
            while (!cisEmpty() && cpeek() != '(') res[j++] = cpop();
            cpop();
        } else if (isOp(c)) {
            while (!cisEmpty() && prec(cpeek()) >= prec(c)) res[j++] = cpop();
            cpush(c);
        }
        i++;
    }
    while (!cisEmpty()) res[j++] = cpop();
    res[j] = '\0';
    printf("Postfix: %s\n", res);
}
struct INode {
    int data;
    struct INode *next;
};
struct INode *itop = NULL;
void ipush(int v) {
    struct INode *n = (struct INode *)malloc(sizeof(struct INode));
    n->data = v; n->next = itop; itop = n;
}
int ipop() {
    if (!itop) return 0;
    int v = itop->data;
    struct INode *t = itop; itop = itop->next; free(t);
    return v;
}
void evalPostfix() {
    char expr[100];
    int i;
    printf("Enter postfix: ");
    scanf("%s", expr);
    itop = NULL;
    for (i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (isdigit(c)) { ipush(c - '0'); }
        else {
            int b = ipop(), a = ipop();
            if (c == '+') ipush(a + b);
            else if (c == '-') ipush(a - b);
            else if (c == '*') ipush(a * b);
            else if (c == '/') ipush(a / b);
        }
    }
    printf("Result: %d\n", ipop());
}
int main() {
    int ch;
    while (1) {
        printf("\n1.Infix to postfix 2.Eval postfix 3.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) infixToPostfix();
        else if (ch == 2) evalPostfix();
        else if (ch == 3) break;
        else printf("Invalid\n");
    }
    return 0;
}
