#include <stdio.h>

#define MAX 100

int arr[MAX];
int top1 = -1;
int top2;
int size;

void push1(int value)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow\n");
        return;
    }

    arr[++top1] = value;
}

void push2(int value)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow\n");
        return;
    }

    arr[--top2] = value;
}

void pop1()
{
    if (top1 == -1)
    {
        printf("Stack 1 Underflow\n");
        return;
    }

    printf("Popped from Stack 1: %d\n", arr[top1--]);
}

void pop2()
{
    if (top2 == size)
    {
        printf("Stack 2 Underflow\n");
        return;
    }

    printf("Popped from Stack 2: %d\n", arr[top2++]);
}

void display()
{
    int i;

    printf("Stack 1: ");
    for (i = 0; i <= top1; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("Stack 2: ");
    for (i = size - 1; i >= top2; i--)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int choice, value;

    printf("Enter size of stack: ");
    scanf("%d", &size);

    if (size > MAX || size <= 0)
    {
        printf("Invalid size\n");
        return 0;
    }

    top2 = size;

    while (1)
    {
        printf("\n1. Push in Stack 1");
        printf("\n2. Pop from Stack 1");
        printf("\n3. Push in Stack 2");
        printf("\n4. Pop from Stack 2");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push1(value);
                break;

            case 2:
                pop1();
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                push2(value);
                break;

            case 4:
                pop2();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("\nFinal contents of both stacks:\n");
                display();
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
