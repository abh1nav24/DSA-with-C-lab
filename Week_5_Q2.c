#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int *queue;
int front, rear;

/* Create Queue */
void Create()
{
    queue = (int *)malloc(MAX * sizeof(int));

    if (queue == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    front = 0;
    rear = -1;
}

/* Insert element into queue */
void EnQueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    rear++;
    queue[rear] = value;
}

/* Display Queue */
void Display()
{
    int i;

    for (i = front; i <= rear; i++)
    {
        printf("%d", queue[i]);

        if (i < rear)
            printf(" ");
    }

    printf("\n");
}

/* Reverse Queue */
void Reverse()
{
    int i = front;
    int j = rear;
    int temp;

    while (i < j)
    {
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;

        i++;
        j--;
    }
}

int main()
{
    int choice, value;

    Create();

    printf("Press:\n");
    printf("1 to insert\n");
    printf("2 to exit\n");

    while (1)
    {
        scanf("%d", &choice);

        if (choice == 1)
        {
            scanf("%d", &value);
            EnQueue(value);
        }
        else if (choice == 2)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    printf("Initial Queue : ");
    Display();

    Reverse();

    printf("Reverse Queue : ");
    Display();

    free(queue);

    return 0;
}
