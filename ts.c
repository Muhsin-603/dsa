#include<stdio.h>
int r,c,a[20][20],s[20][20],t[20][20],k=1,count;
void sp();
void tp();
int main(){
    int i,j;
    printf("Enter the number of rows and coloumns : ");
    scanf("%d%d",&r,&c);
    printf("Enter the matrix :\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    sp();
    tp();
    return 0;
}
void sp(){
    int i,j;
    s[0][0] = r;
    s[0][1] = c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j] != 0){
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;count++;
            }
        }
    }
    s[0][2] = count;
    printf("row\tcoloumn\telement\n");
    printf("%d\t%d\t%d\n",s[0][0],s[0][1],s[0][2]);
    for(i=1;i<k;i++){
        printf("%d\t%d\t%d\n",s[i][0],s[i][1],s[i][2]);
    }
}
void tp(){
    int i;
    t[0][0] = c;
    t[0][1] = r;
    t[0][2] = s[0][2];
    for(i=1;i<k;i++){
        t[i][0] = s[i][1];
        t[i][1] = s[i][0];
        t[i][2] = s[i][2];
    }
    printf("row\tcoloumn\telement\n");
    printf("%d\t%d\t%d\n",t[0][0],t[0][1],t[0][2]);
    for(i=1;i<k;i++){
        printf("%d\t%d\t%d\n",t[i][0],t[i][1],t[i][2]);
    }
}