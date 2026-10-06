#include<stdio.h>
int main(){
    int n1,n2;
    scanf("%d",&n1);
    int a[n1];
    for(int i=0;i<n1;i++) scanf("%d",&a[i]);
    scanf("%d",&n2);
    int b[n2];
    for(int i=0;i<n2;i++) scanf("%d",&b[i]);
    printf("Intersection: ");
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a[i]==b[j]) printf("%d ",a[i]);
        }
    }
}