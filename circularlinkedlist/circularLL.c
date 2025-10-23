#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;


void insertBegin(int value){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;

    if (head==NULL){
        newNode->next=newNode;
        head=newNode;
    } else {
        struct Node* temp= head;

        while(temp->next != head){
            temp=temp->next;

        }

        newNode->next=head;
        temp->next=newNode;
        head=newNode;
    }
    printf("Inserted %d at begining ", value);
}


void insertEnd(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;

    if (head==NULL){
        newNode->next=newNode;
        head=newNode;
    } else {
        struct Node* temp=head;
        while(temp->next != head)
            temp=temp->next;
        
        temp->next=newNode;
        newNode->next=head;


    }
    printf("Inserted %d at end", value);
}




void insertAtPos(int value, int pos) {
    if (pos < 1) {
        printf("Position must be >= 1\n");
        return;
    }

    if (pos == 1) {
        insertBegin(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d\n", value, pos);
}


void deleteBegin() {
    if (head == NULL) {
        printf("List empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;


    if (head->next == head) {
        head = NULL;
        printf("Deleted %d from beginning\n", temp->data);
        free(temp);
        return;
    }

    struct Node* last = head;
    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}


void deleteEnd() {
    if (head == NULL) {
        printf("List empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;

 
    if (head->next == head) {
        head = NULL;
        printf("Deleted %d from end\n", temp->data);
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    printf("Deleted %d from end\n", temp->data);
    free(temp);
}


void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("List empty. Nothing to delete.\n");
        return;
    }

    if (pos < 1) {
        printf("Position must be >= 1\n");
        return;
    }

    if (pos == 1) {
        deleteBegin();
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 1;

    while (count < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count != pos) {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted %d from position %d\n", temp->data, pos);
    free(temp);
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void search(int value) {
    if (head == NULL) {
        printf("List is empty. Nothing to search.\n");
        return;
    }

    struct Node* temp = head;
    int pos = 1;

    do {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;  
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Value %d not found in the list.\n", value);
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
                insertBegin(value);
                break;
            case 2:
                
                printf("Enter Number to insert: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                
                printf("Enter Number to insert: ");
                scanf("%d",&value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPos(value, pos);
                break;
            case 4:
                
                printf("First node deleted\n");
                deleteBegin();
                break;
            case 5:
                
                printf("last node deleted\n");
                deleteEnd();
                break;
            case 6:
               
                printf("Enter node position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
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

