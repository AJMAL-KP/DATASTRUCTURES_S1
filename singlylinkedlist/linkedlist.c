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

void deleteFirst() {
    if (head == NULL){
        printf("Linked list is empty \n");
        return;
    }

    struct node* temp=head;
    head=head->next;
    free(temp);
}

void deleteEnd(){
    if (head == NULL){
        printf("LL is empty \n");
        return;
    }

    if(head->next == NULL){
        free(head);
        head=NULL;
        return;
        
    }

    struct node* temp = head;
    struct node* prev =NULL;

    while(temp->next != NULL) {
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=NULL;

}

void deleteAtpos(int pos){

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos==1){
        deleteFirst();
        return;
    }

    struct node* temp = head;

    for(int i=1;i<pos-1 && temp != NULL;i++){
        temp=temp->next;
    }

    struct node* del= temp->next;
    temp->next = del->next;
    free(del);
    


}

void search(int value){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    
    int found=0;
    struct node* temp=head;
    for(int i=1; i > 0 && temp != NULL;i++){
        if( temp->data == value){
            printf("Element %d found at %d position\n", value,i);
            found=1;
            
        }
        temp=temp->next;
        

    }
    if (found==0) {
        printf("No such element in list\n");
    }
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
        printf("\n1.Insert at begining\n2.Insert at end.\n3.Insert at position\n4.Delete First node\n5.Delete last node\n6.Delete from position\n7.Search\n8.Display\n9.Exit\n");
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
            case 4:
                printf("First node deleted\n");
                deleteFirst();
                break;
            case 5:
                printf("last node deleted\n");
                deleteEnd();
                break;
            case 6:
                printf("Enter node position to delete: ");
                scanf("%d", &pos);
                deleteAtpos(pos);
                break;
            case 7:
                printf("Enter data to search:");
                scanf("%d",&value);
                search(value);
                break;
            case 8:
                display();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid Operation\n");
        }
    }
}

