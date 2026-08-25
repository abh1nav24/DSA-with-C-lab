#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct queue{
    int *arr;
    int front;
    int rear;
} queue;


void create(queue *q);
void enqueue(queue *q, int k);
void dequeue(queue *q);
int isempty(queue *q);
int size(queue *q);


int main(){
    queue q;
    int choice, k;

    create(&q);

    while(1){
        printf("\n1 to enqueue");
        printf("\n2 to dequeue");
        printf("\n3 to calculate size");
        printf("\n4 to exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter element: ");
                scanf("%d", &k);
                enqueue(&q, k);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                printf("Size = %d\n", size(&q));
                break;

            case 4:
                free(q.arr);
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}


void create(queue *q){
    q->arr = (int *)malloc(MAX * sizeof(int));
    q->front = -1;
    q->rear = -1;
}


void enqueue(queue *q, int k){
    if(q->rear == MAX - 1){
        printf("Overflow");
    }

    if(q->front == -1){
        q->front++;
    }

    q->arr[++q->rear] = k;
}


void dequeue(queue *q){
    if(q->front == -1){
        printf("Underflow");
    }else{
        printf("Deleted = %d", q->arr[q->front]);

        q->front++;

        if(q->front > q->rear){
            q->front = -1;
            q->rear = -1;
        }
    }
}


int isempty(queue *q){
    if(q->front == -1)
        return 1;
    else
        return 0;
}


int size(queue *q){
    if(isempty(q))
        return 0;

    return q->rear - q->front + 1;
}
