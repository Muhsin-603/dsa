#include<stdio.h>
int max,top=-1,a[100],q[100];
int v,front=-1,rear=-1;

void enqueue(){
    if(rear == max-1){
        printf("The queue is full");
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        printf("Enter the value to enqueue : ");
        scanf("%d",&v);
        q[rear] = v;
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("The queue is empty : ");
    }
    else{
        printf("The value enqueued is %d",q[front]);
        front++;
    }
}



void push(int d){
    if(top == max-1){
        printf("Stack overflow");
    }
    else{
        ++top;
        a[top]=d;
        printf("The value pushed is : %d",d);
    }
}
void pop(){
    if(top==-1){
        printf("Stack underflow");
    }
    else{
        
        printf("The value popped is : %d",a[top]);
        top--;
    }
}

void display(){
    int i;
    for(i=0;i<top;i++){
        printf("%d\t",a[i]);
    }
}
int main(){
int a;
printf("Enter the limit of the stack : ");
scanf("%d",&max);
printf("Enter the value u want to push : ");
scanf("%d",&a);
push(a);
scanf("%d",&a);
push(a);
scanf("%d",&a);
push(a);
scanf("%d",&a);
push(a);
display();
pop();
pop();
display();
}