#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* create(int d){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=d;
    newNode->next=NULL;
    return newNode;
}

void insert(int d,struct Node** h){
    struct Node* newNode = create(d);
    if(*h == NULL){
        *h = newNode;
    }
    else{
        struct Node* t = *h;
        while(t->next != NULL){
            t = t->next;
        }
        t ->next = newNode;
    }
}

void combine(struct Node** h1,struct Node** h2,struct Node** h3){
struct Node* p1 = *h1;
struct Node* p2 = *h2;
while(p1 != NULL && p2 != NULL){
    insert(p1->data,h3);
    insert(p2->data,h3);
    p1 = p1->next;
    p2 = p2->next;
}
}

void display(struct Node** h){
    struct Node* p = *h;
    while(p != NULL){
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    int d,i,n;
    struct Node* h1 = NULL;
    struct Node* h2 = NULL;
    struct Node* h3 = NULL;
    printf("Enter the number of elements list should contain : ");
    scanf("%d",&n);
    printf("Enter the elements of the 1st list\n");
    for(i=0;i<n;i++){
        printf("Enter the element to insert : ");
        scanf("%d",&d);
        insert(d,&h1);
    }
    printf("Enter the elements of the 2nd list\n");
    for(i=0;i<n;i++){
        printf("Enter the element to insert : ");
        scanf("%d",&d);
        insert(d,&h2);
    }
    combine(&h1,&h2,&h3);
    printf("The first list : ");
    display(&h1);
    printf("The second list : ");
    display(&h2);
    printf("The combined list : ");
    display(&h3);
}