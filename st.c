#include<stdio.h>
void is(int a[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
void bs(int a[],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int bsearch(int a[],int k,int n){
    int high,low,mid,r;
    low = 0;
    high = n;
    while(low<=high){
        mid = (high - low)/2;
        if(a[mid] == k){
            r = mid;
            break;
        }
        else if(a[mid] > k)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return r;  
}
void ss(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            }
        }
    }
}
int main(){
    int n,i,a[50];
    //int k,r;
    printf("no of elements : ");
    scanf("%d",&n);
    printf("Enter the elements of the array : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ss(a,n);
    printf("The sorted array is : ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    /*printf("Enter the key u want to search : ");
    scanf("%d",&k);
    r = bsearch(a,k,n);
    printf("The element found at %d",r+1);*/
}