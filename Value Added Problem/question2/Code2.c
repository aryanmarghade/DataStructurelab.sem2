#include <stdio.h>

int main() {
     printf(" NAME: Aryan Marghade \n PRN: 25070521215 \n SECTION: D(D2) \n SUBJECT: Data  Structures Lab \n");
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
