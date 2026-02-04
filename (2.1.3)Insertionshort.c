#include <stdio.h>

int main() {
  int  a[20],n,i,key,j;
printf("Enter the number of element : ");
  scanf("%d",&n);
printf("Enter the number of elements in array : ");
  for(i=0;i<n;i++){
      scanf("%d",&a[i]);
  }

  for(i=1;i<n;i++){
      key=a[i];
      j=i-1;
      if( j>=0 && key < a[j]){
          a[j+1]=a[j];
          j--;
      }
      a[j+1]=key;
  }
 printf("After shorting the array are\n");
  for(i=0;i<n;i++){
      printf("%d\n",a[i]);
  }

    return 0;
}
