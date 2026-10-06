#include<stdio.h>
int main(){
    int n1,n2;
    scanf("%d",&n1);
    int a[n1];
    for(int i=0;i<n1;i++) scanf("%d",&a[i]);
    scanf("%d",&n2);
    int b[n2];
    for(int i=0;i<n2;i++) scanf("%d",&b[i]);
    int k=0;
    int u[200];
    for(int i=0;i<n1;i++){
        u[k]=a[i];
        k++;
    }
    for(int i=0;i<n2;i++){
        int found = 0;
        for(int j=0;j<n1;j++){
            if(b[i]==a[j]){
                found = 1;
                break;
            }
        }
    if(found==0) u[k++]=b[i];
    }
    printf("Union: ");
    for(int i=0;i<k;i++) printf("%d ",u[i]);
}