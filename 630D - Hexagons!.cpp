#include<stdio.h>

int main(){
	long long int x;
	long long int s=0;
	scanf("%lld",&x);
s=(x*(x+1))/2;
	s=s*6+1;
	printf("%lld",s);
return 0;
}