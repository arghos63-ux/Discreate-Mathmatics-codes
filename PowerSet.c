#include<stdio.h>
int main(){
   FILE *file;
   file=fopen("Power.txt","r");
   if(file==NULL){
    printf("Error");
    return 1;
   }
   int n;
   fscanf(file,"%d",&n);
   int a[n]; 
   for(int i=0;i<n;i++){
      fscanf(file,"%d",&a[i]);
   }
   fclose(file);
   printf("Power set: ");
   int total = 1<<n;
   for(int i=0;i<total;i++){
      printf(" {");
      for(int j=0;j<n;j++){
         if(i&(1<<j)) printf("%d",a[j]);
      }
       printf("} ");
   }
   printf("\nTotal subset: %d ",total);
}