#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* CNnode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode; 
};

void INnode(struct Node** head,int d){
    struct Node* newNode = CNnode(d);
    newNode->next = *head;
    *head = newNode;
}

void IEnode(struct Node** head,int d){
    struct Node* newNode = CNnode(d);
    if(*head == NULL){
        *head = newNode;
    }
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void IKnode(struct Node** head,int d,int k){
    struct Node* newNode = CNnode(d);
    struct Node* ptr = *head;
    while(ptr->data!=k && ptr != NULL){
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("Key not found");
        free(newNode);
    }
    else{
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void Pnode(struct Node** head){
    struct Node* ptr = *head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
}

void DInode(struct Node** head){
    
    if(*head == NULL){
        printf("List is empty");
    }
    else{
        struct Node* ptr = *head;
        *head = ptr->next;
        free(ptr);
    }
}

void DEnode(struct Node** head){
    struct Node* ptr = *head;
    if(*head == NULL){
        printf("The list is empty");
    }
    
    else if(ptr->next == NULL){
        free(ptr);
        *head = NULL;
    }
    else{
        
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }
}
void DPnode(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    // If deleting first node
    if (pos == 1) {
        DInode(&head);
        return;
    }

    // Traverse to the node BEFORE the deleting one
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If position invalid
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main(){
    int h;
    struct Node* head = NULL;
    printf("Enter the value : ");
    scanf("%d",&h);
    INnode(&head,h);
    printf("Enter the value : ");
    scanf("%d",&h);
    IEnode(&head,h);
    Pnode(&head);
}