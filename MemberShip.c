#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int x,found=0;
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        if(a[i]==x){
            found = 1;
            break;
        }
    }
    if(found == 1) printf("%d is a member of the set.",x);
    else printf("%d is not the member of the set.",x);
}