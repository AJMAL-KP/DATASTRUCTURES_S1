#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
    
};

struct node *head = NULL;
struct node *head2 = NULL;


void insertFirst (int value, int ll) {
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> data = value;

    if (ll==1){ 
    new_node ->next =head;
    new_node-> prev=NULL;
    head = new_node;
    }
    else if (ll == 2){
        new_node ->next =head2;
        new_node-> prev=NULL;
        head2 = new_node;
    }
    else {
        printf("invalid linkedlist!");
    }

}

void insertEnd(int value, int ll){

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* temp =head ;
    struct node* temp2 =head2 ;


    new_node->data = value;
    new_node->next=NULL;
    

    if ( ll == 1) {
    if ( head == NULL){
        head = new_node;
        new_node ->prev=NULL;
        return;
    }

    while ( temp -> next != NULL) {
        temp = temp -> next ;
    }
    temp->next= new_node;
    new_node->prev=temp;
    
    }
    else if(ll==2){

     if ( head2 == NULL){
        head2 = new_node;
        new_node->prev=NULL;
        return;
    }

    while ( temp2 -> next != NULL) {
        temp2 = temp2 -> next ;
    }
    temp2->next= new_node;
    new_node->prev=temp2;

    }
    else {
        printf("invalid linkedlist!");
    }
    
   
}


void insertAtpos(int value, int pos, int ll) {

    
    if ( ll==1 && ( pos==1 || head == NULL)){
        insertFirst(value, ll);
        return;
    }

    if ( ll==2 && ( pos==1 || head2 == NULL)){
        insertFirst(value, ll);
        return;
    }

    struct node* new_node = (struct node *) malloc (sizeof(struct node));
    struct node* temp = head ;
    struct node* temp2 = head2 ;
    new_node->data=value;


    if (ll==1){
    for(int i=1; i<pos-1 && temp != NULL;i++){
        temp = temp -> next ;
     

    }
       new_node->next=temp->next;
        temp->next=new_node;
        new_node->prev = temp;

    if (temp == NULL) {
        printf("Position %d is out of range.\n", pos);
        free(new_node);  
        return;
    }

    else if(ll==2){
        
        for(int i=1; i<pos-1 && temp2 != NULL;i++){
        temp2 = temp2 -> next ;
      
    }
      new_node->next=temp->next;
        temp->next = new_node;
        new_node->prev=temp;
    } 

    if (temp2 == NULL) {
        printf("Position %d is out of range.\n", pos);
        free(new_node);  
        return;
    }
   

}}



void deleteFirst(int ll) {
    if (ll==1){
    if (head == NULL){
        printf("Linked list is empty \n");
        return;
    }

    struct node* temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
} 
else if(ll==2){
    if (head2 == NULL){
        printf("Linked list is empty \n");
        return;
    }

    struct node* temp2=head2;
    head2=head2->next;
    head2->prev=NULL;
    free(temp2);

}
else {
    printf("Invalid list\n");
}
}

void deleteEnd(int ll){
    if(ll==1){

    
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
    else if(ll==2){

        if (head2 == NULL){
        printf("LL2 is empty \n");
        return;
    }

    if(head2->next == NULL){
        free(head2);
        head2=NULL;
        return;
        
    }

    struct node* temp2 = head2;
    struct node* prev2 =NULL;

    while(temp2->next != NULL) {
        prev2=temp2;
        temp2=temp2->next;
    }
    free(temp2);
    prev2->next=NULL;

    }
    else{
        printf("invalid list\n");
    }
}

void deleteAtpos(int pos,int ll){
    if(ll==1){

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos==1){
        deleteFirst(ll);
        return;
    }

    struct node* temp = head;

    for(int i=1;i<pos-1 && temp != NULL;i++){
        temp=temp->next;
    }

    struct node* del= temp->next;
    temp->next = del->next;
    del->next->prev=temp;
    free(del);
}
else if(ll==2){

     if (head2 == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos==1){
        deleteFirst(ll);
        return;
    }

    struct node* temp2 = head2;

    for(int i=1;i<pos-1 && temp2 != NULL;i++){
        temp2=temp2->next;
    }

    struct node* del2= temp2->next;
    temp2->next = del2->next;
    del2->next->prev = temp2;
    free(del2);

}
else{
    printf("invalid list\n");
}

}

void search(int value,int ll){
    if(ll==1){

    
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
else if(ll==2){

      
    if(head2 == NULL){
        printf("List is empty\n");
        return;
    }
    
    int found=0;
    struct node* temp2=head2;
    for(int i=1; i > 0 && temp2 != NULL;i++){
        if( temp2->data == value){
            printf("Element %d found at %d position\n", value,i);
            found=1;
            
        }
        temp2=temp2->next;
        

    }
    if (found==0) {
        printf("No such element in list\n");
    }


}
else {
    printf("Invalid list\n");
}
}





void display(int ll) {

    if(ll==1){
        if (head == NULL) {
        printf("Empty\n");
        }

        else {
        struct node *temp = head;
        printf("First List : \n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        }
    }
        
    else if(ll==2){
        if (head2 == NULL) {
        printf("Second list Empty\n");
    }
    else {
        struct node *temp2 = head2;
        printf("Second List : \n");
        while (temp2 != NULL) {
            printf("%d ", temp2->data);
            temp2 = temp2->next;
        }
        printf("\n");

    }
}
else {
    printf("invalid list\n");
}
  
}

void merge(){

    struct node* temp= head;
    if (head == NULL || head2 == NULL) {
        
        return;
    }
    while( temp->next != NULL){
        temp=temp->next;
    }
    temp->next=head2;
    head2->prev=temp;
    head2=NULL;
    display(1);

}






int main() {
    int op, value, pos, ll;
    while (1) {
        printf("\n1.Insert at begining\n2.Insert at end.\n3.Insert at position\n4.Delete First node\n5.Delete last node\n6.Delete from position\n7.Search\n8.Display\n9.Merge\n10.Exit\n");
        printf("Choose Operation: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Linked List 1 or 2?");
                scanf("%d", &ll);
                printf("Enter Number to insert: ");
                scanf("%d", &value);
                insertFirst(value, ll);
                break;
            case 2:
                printf("Linked List 1 or 2?");
                scanf("%d", &ll);
                printf("Enter Number to insert: ");
                scanf("%d", &value);
                insertEnd(value,ll);
                break;
            case 3:
                printf("Linked List 1 or 2?");
                scanf("%d", &ll);
                printf("Enter Number to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtpos(value, pos, ll);
                break;
            case 4:
                printf("Linked List 1 or 2?");
                scanf("%d", &ll);
                printf("First node deleted\n");
                deleteFirst(ll);
                break;
            case 5:
                printf("Linked List 1 or 2?");
                scanf("%d", &ll);
                printf("last node deleted\n");
                deleteEnd(ll);
                break;
            case 6:
                printf("Linked List 1 or 2?");
                scanf("%d", &ll);
                printf("Enter node position to delete: ");
                scanf("%d", &pos);
                deleteAtpos(pos,ll);
                break;
            case 7:
                printf("Linked List 1 or 2?");
                scanf("%d", &ll);
                printf("Enter data to search:");
                scanf("%d",&value);
                search(value,ll);
                break;
            case 8:
                printf("Linked List 1 or 2?");
                scanf("%d", &ll);
                display(ll);
                break;
            case 9:
                merge();
                break;
            case 10:
                return 0;
            default:
                printf("Invalid Operation\n");
        }
    }
}

