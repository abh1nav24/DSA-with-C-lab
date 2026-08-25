#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void Create();
void Enqueue(int k);
void Dequeue();
int IsEmpty();
int Size();

int c = 0;

int main(){
    int choice, k;

    Create();

    while (1){
        printf("\n1 to enqueue\n");
        printf("2 to dequeue\n");
        printf("3 to calculate size\n");
        printf("4 to exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                scanf("%d", &k);
                Enqueue(k);
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                printf("Size = %d\n", Size());
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}


void Create(){
    front = -1;
    rear = -1;
    c = 0;
}


void Enqueue(int k){
    if (rear == MAX - 1){
        printf("Queue Overflow\n");
    }else{
        if (front == -1){
            front = 0;
        }

        rear++;
        queue[rear] = k;
        c++;

        printf("Queue - ");

        for (int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}


void Dequeue()
{
    if (IsEmpty()){
        printf("Queue Underflow\n");
    }else{
        printf("Deleted element = %d\n", queue[front]);

        front++;
        c--;

        if (front > rear){
            front = -1;
            rear = -1;
        }

        printf("Queue - ");

        for (int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}


int IsEmpty(){
    if (front == -1){
        return 1;
    }else{
        return 0;
    }
}


int Size(){
    return c;
}
