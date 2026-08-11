#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int top = -1;
    char c[MAX];
    char s[MAX];

    scanf("%s", c);

    for (int i = 0; i < strlen(c); i++) {
        if (c[i] == '(' || c[i] == '{' || c[i] == '[') {
            s[++top] = c[i];
        }
        else if (c[i] == ')' || c[i] == '}' || c[i] == ']') {
            if (top == -1) {
                printf("Not Balanced");
                return 0;
            }

            if ((c[i] == ')' && s[top] == '(') || (c[i] == '}' && s[top] == '{') ||(c[i] == ']' && s[top] == '[')) {
                top--;
            }
            else {
                printf("Not Balanced");
                return 0;
            }
        }
    }
    if (top == -1)
        printf("Balanced");
    else
        printf("Not Balanced");
    return 0;
}
