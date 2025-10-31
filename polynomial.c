#include<stdio.h>
struct poly
{
    int coeff;
    int exp;
}p1[10],p2[10],r[10];


int main()
{
    int t1,t2,i,j,k;
    printf("Enter the number of terms of 1st polynomial : ");
    scanf("%d",&t1);
    for(i=0;i<t1;i++){
        printf("Enter the %d coeff",i+1);
        scanf("%d",&p1[i].coeff);
        printf("Enter the %d exp",i+1);
        scanf("%d",&p1[i].exp);
    }i=0;
    printf("Enter the number of terms of 2nd polynomial : ");
    scanf("%d",&t2);
    for(i=0;i<t2;i++){
        printf("Enter the %d coeff",i+1);
        scanf("%d",&p2[i].coeff);
        printf("Enter the %d exp",i+1);
        scanf("%d",&p2[i].exp);
    }i=0,j=0,k=0;

    while(i<t1 && j<t2){
        if(p1[i].exp > p2[j].exp){
            r[k].coeff = p1[i].coeff; 
            r[k].exp = p1[i].exp;
            i++;k++;
        }
        else if(p1[i].exp < p2[j].exp){
            r[k].coeff = p2[j].coeff;
            r[k].exp = p2[j].exp;
            k++;j++;
        }
        else{
            r[k].coeff = p1[i].coeff + p2[j].coeff;
            r[k].exp = p1[i].exp;
            i++;j++;k++;
        }
    }
    while(i < t1){
        r[k].coeff = p1[i].coeff; 
        r[k].exp = p1[i].exp;
        i++;k++;
    }
    while(j < t2){
        r[k].coeff = p2[j].coeff; 
        r[k].exp = p2[j].exp;
        j++;k++;
    }
    printf("The first polynomial : ");
    printf("%dx^%d",p1[0].coeff,p1[0].exp);
    for(i=1;i<t1;i++){
        printf("+%dx^%d",p1[i].coeff,p1[i].exp);
    }
    printf("\n");
    printf("The second polynomial : ");
    printf("%dx^%d",p2[0].coeff,p2[0].exp);
    for(i=1;i<t2;i++){
        printf("+%dx^%d",p2[i].coeff,p2[i].exp);
    }
    printf("\n");
    printf("The result polynomial : ");
    printf("%dx^%d",r[0].coeff,r[0].exp);
    for(i=1;i<t2;i++){
        printf("+%dx^%d",r[i].coeff,r[i].exp);
    }
    printf("\n");
    return 0;
}