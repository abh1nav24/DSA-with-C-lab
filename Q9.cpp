#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int top = -1;
    char c[MAX];
    char s[MAX];
    int count=0;

    scanf("%s", c);

    for (int i = 0; i < strlen(c); i++) {
        if (c[i] == '(') {
            s[++top] = c[i];

        } 
        else if (c[i] == ')' ) {
            if (top == -1) {
                continue;
            }

            if (s[top]=='('){
                top--;
                count+=2;
            }
        }  
    }
    printf("%d", count);
   
    return 0;
}
