#include<stdio.h>
int main(){
    FILE *file = fopen("One To One.txt","r");
    if(file == NULL){
        printf("Error");
        return 1;
    }
    int n1,n2;
    fscanf(file,"%d",&n1);
    int domain[n1];
    for(int i=0;i<n1;i++) fscanf(file,"%d",&domain[i]);
    fscanf(file,"%d",&n2);
    int range[n2];
    for(int i=0;i<n2;i++) fscanf(file,"%d",&range[i]);
    fclose(file);
    int one = 1;
    for(int i=0;i<n2;i++){
        for(int j=i+1;j<n2;j++){
            if(range[i]==range[j]){
                one = 0;
                break;
            }
        }
        if(one==0) break;
    }
     if(one==1) printf("Function is one to one.\n");
        else printf("Function is not one to one.\n");
}