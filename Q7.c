#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Create stack
void create()
{
    top = -1;
    printf("Stack created successfully.\n");
}

// Push element
void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
        printf("%d pushed into stack.\n", x);
    }
}

// Pop element
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

// Check if stack is empty
void isEmpty()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack is Not Empty\n");
    }
}

// Find size of stack
void size()
{
    printf("Size = %d\n", top + 1);
}

// Print stack
void print()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack - ");

        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;
    int x;

    create();

    do
    {
        printf("\n----- STACK MENU -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Size\n");
        printf("5. Print\n");
        printf("6. Create\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                isEmpty();
                break;

            case 4:
                size();
                break;

            case 5:
                print();
                break;

            case 6:
                create();
                break;

            case 7:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
