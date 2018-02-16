#include<stdio.h>
#include<stdlib.h>

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
int main(){
int n,m,q;
int* arr;
scanf("%d %d",&n,&m);
arr=(int*)malloc(n*sizeof(int));
for(int i=0 ;i<n;i++)
{
scanf("%d",&arr[i]);
}
quickSort(arr,0,n-1);
printf("%d",arr[m-1]);
//int best;
//int temp;
//for(int i=0 ; i<m ; i++){
// best=i;
// for(int j=i+1; j<n ; j++){
//	 if(arr[j]<arr[best]){
//	 best=j;
//	 }
// }
// temp=arr[i];
// arr[i]=arr[best];
// arr[best]=temp;
//}
//printf("%d",arr[m-1]);
return 0;
}
close