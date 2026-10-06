#include<stdio.h>
int f(int x){
    return 2*x+3;
}
int main(){
    int x;
    scanf("%d",&x);
    printf( "%d", f(x));
}