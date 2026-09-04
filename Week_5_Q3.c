#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int *deque;
int front = -1;
int rear = -1;
int count = 0;

/* Create Deque */
void Create()
{
    deque = (int *)malloc(MAX * sizeof(int));

    if (deque == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    front = -1;
    rear = -1;
    count = 0;
}

/* Check if Deque is Empty */
int isEmpty()
{
    return count == 0;
}

/* Check if Deque is Full */
int isFull()
{
    return count == MAX;
}

/* Insert at Front */
void insertFront(int value)
{
    if (isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = value;
    count++;
}

/* Insert at End */
void insertEnd(int value)
{
    if (isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = value;
    count++;
}

/* Delete from Front */
void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    if (count == 1)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    count--;
}

/* Delete from End */
void deleteEnd()
{
    if (isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    if (count == 1)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear - 1 + MAX) % MAX;
    }

    count--;
}

/* Print Deque from Front */
void printFront()
{
    int i, index;

    printf("Contents of queue from front - ");

    if (isEmpty())
    {
        printf("Empty\n");
        return;
    }

    index = front;

    for (i = 0; i < count; i++)
    {
        printf("%d", deque[index]);

        if (i < count - 1)
            printf(" ");

        index = (index + 1) % MAX;
    }

    printf("\n");
}

/* Print Deque from End */
void printEnd()
{
    int i, index;

    printf("Contents of queue from end - ");

    if (isEmpty())
    {
        printf("Empty\n");
        return;
    }

    index = rear;

    for (i = 0; i < count; i++)
    {
        printf("%d", deque[index]);

        if (i < count - 1)
            printf(" ");

        index = (index - 1 + MAX) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    Create();

    while (1)
    {
        printf("\nPress:\n");
        printf("1 insert at front\n");
        printf("2 insert at end\n");
        printf("3 delete from front\n");
        printf("4 delete from end\n");
        printf("5 to exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                printFront();
                printEnd();

                free(deque);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
