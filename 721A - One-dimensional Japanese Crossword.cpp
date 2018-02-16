#include<stdio.h>

int main(){
int flag=0,n,p=0,r[50],n1=0;
scanf("%d",&n);
char c,e;
scanf("%c",&e);
for(int i=0 ; i<n ;i++){
	scanf("%c",&c);	
	if(c-'B'==0){
		p++;
	}
	else{
	if(p>0){
		r[n1]=p;
		n1++;
		p=0;
	}
	}
}
if(p>0){
r[n1]=p;
n1++;
}
printf("%d\n",n1);
for(int i=0 ; i<n1 ;i++){
printf("%d ",r[i]);
}
return 0;
}