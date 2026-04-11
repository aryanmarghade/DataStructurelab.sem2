#include <stdio.h>

int main() {
    char s[1000], st[1000];
    int top = -1, i = 0;

    scanf("%s", s);

    while (s[i] != '\0') {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st[++top] = s[i];
        } else {
            if (top == -1) {
                printf("Not Balanced");
                return 0;
            }

            if ((s[i] == ')' && st[top] == '(') ||
                (s[i] == '}' && st[top] == '{') ||
                (s[i] == ']' && st[top] == '[')) {
                top--;
            } else {
                printf("Not Balanced");
                return 0;
            }
        }
        i++;
    }

    if (top == -1)
        printf("Balanced");
    else
        printf("Not Balanced");

    return 0;
}
