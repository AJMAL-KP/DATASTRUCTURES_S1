#include<stdio.h>

int arr[100],  size,  pos,  num;

void insert(){
    printf("Enter how many elements to enter?\n");
    scanf("%d",&size);
    printf("ENter the elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d", &arr[i]);

    }

}


int search(int num){
    for(int i=0;i<size;i++)
    {
        if ( arr[i]==num){
            return i;
        }
    }

}

int delete(){

    printf("enter the number you want to delete:\n");
    scanf("%d",&num);
    pos=search(num);
    for(int i=pos; i<size;i++)
    {
        if(i==size-1){
            arr[i]=0;
        }
        else{
        arr[i]=arr[i+1];
       
    }


}



}

void display(){

    printf("The elements are:\n");
    for(int i=0;i<size;i++){
        printf("[%d]",arr[i]);
    }
}

void sort(){
    for(int i=1;i<size;i++){
        if ( arr[i] < arr[i-1]) {
            int temp = arr[i -1];
            arr[i-1] = arr[i];
            arr[i]= temp;
        }
    }
    printf("Final sorted array is: \n");
    display();
}


int main() {
int op;
int value;
while (1)
{
   
printf( " \n 1.Insert \n 2.Delete \n 3.Display\n 4.search \n 5. sort \n 6.exit \n");
printf( "Choose Operation : \n");
scanf("%d" , &op);

switch (op)
{
case 1:
    insert();
    break;

case 2:
    delete();
    break;

case 3:
    display();
    break;

case 4:
    printf("Enter the number you want to search?\n");
    scanf("%d",&num);
    pos=search(num);
    printf("number found at %d position \n", pos);
    break;

case 5:
    sort();
    break;

case 6:
    return 0;
    break;

default:
    printf("Invalid Operation \n");
    break;
}
}
}