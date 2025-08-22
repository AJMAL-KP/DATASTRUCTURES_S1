#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head = NULL;


void insertFirst (int value) {
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> data = value;

    new_node ->next =head;
    head = new_node;

}

void insertEnd(int value){

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* temp =head ;
    new_node->data = value;
    new_node->next=NULL;

    if ( head == NULL){
        head = new_node;
        return;
    }

    while ( temp -> next != NULL) {
        temp = temp -> next ;
    }
    temp->next= new_node;
   
}


void insertAtpos(int value, int pos) {

    if ( pos==1 || head == NULL){
        insertFirst(value);
        return;
    }

    struct node* new_node = (struct node *) malloc (sizeof(struct node));
    struct node* temp = head ;
    new_node->data=value;

    for(int i=1; i<pos-1 && temp != NULL;i++){
        temp = temp -> next ;
    }

    if (temp == NULL) {
        printf("Position %d is out of range.\n", pos);
        free(new_node);  
        return;
    }
    new_node->next=temp->next;
    temp->next = new_node;


}



void display() {
    if (head == NULL) {
        printf("Empty\n");
    } else {
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}






int main() {
    int op, value, pos;
    while (1) {
        printf("\n1.Insert at begining\n2.Insert at end.\n3.Insert at position\n4.Delete\n5.Display\n6.Exit\n");
        printf("Choose Operation: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter Number to insert: ");
                scanf("%d", &value);
                insertFirst(value);
                break;
            case 2:
                printf("Enter Number to insert: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter Number to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtpos(value, pos);
                break;
            // case 4:
            //     printf("Enter Number to delete: ");
            //     scanf("%d", &value);
            //     deleteNode(value);
            //     break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid Operation\n");
        }
    }
}

