#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front=-1;
int rear=-1;



void enqueue( int value){

    if ((rear+1%SIZE)==front){
        printf("Queue is Full...!!");

    } else {
        if (front == -1)
            front = 0;
        rear= (rear+1)%SIZE;
        queue[rear]=value;
        printf("Inserted Value %d", value);
    }

}


void dequeue() {
    if (front == -1) {
        printf("queue is empty.Nothing to remove.");
    } else {
        int removed = queue[front];

        if (front==rear){
            front = -1;
            rear = -1;
        }

        else {
            front = (front +1)%SIZE;
        }
        printf("Removed %d", removed);
    }

}

void display(){
    if (front == -1) {
        printf("Queue is empty \n");

    } else {
        printf("queue elements are : \n");
        int i = front;

        while(1){
            printf("[ %d ]", queue[i]);

            if (i==rear)
                break;
            i=(i+1)%SIZE;
        }

    }
}


int main() {
int op;
int value;
while (1)
{
   
printf( " \n 1.Insert \n 2.Delete \n 3.Display\n 4.exit \n");
printf( "Choose Operation : \n");
scanf("%d" , &op);

switch (op)
{
case 1:
    printf("Enter Number to insert : \n");
    scanf("%d", &value);
    enqueue(value);
    break;

case 2:
    dequeue();
    break;

case 3:
    display();
    break;

case 4:
    return 0;
    break;


default:
    printf("Invalid Operation \n");
    break;
}
}
}