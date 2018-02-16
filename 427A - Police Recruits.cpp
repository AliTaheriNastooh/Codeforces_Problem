#include<stdio.h>

int main(){
int n=0 ,u=0;
int i,p;
scanf("%d",&i);
for(int j=0 ; j<i ; j++){
scanf("%d",&p);
if(p>0){
n+=p;
}
else{
	if(p==-1){
		if(n>0){
		n--;
		}
		else{
		u++;
		}
	}
}
}
printf("%d",u);
return 0;
}