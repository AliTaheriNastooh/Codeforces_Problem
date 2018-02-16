#include<stdio.h>
#include<string.h>
int main(){
	long int x;
	long int t;
	long int z;
	//long long int s=0;
	scanf("%lld",&x);
	scanf("%lld",&t);
	scanf("%lld",&z);
	if(x<0)
		x=x*-1;
	if(t<0)
		t=t*-1;
	if(x+t>z){
	printf("NO");
	return 0;
	}
	if((z-(x+t))%2==0){
	printf("YES");
	}
	else
		printf("NO");
return 0;
}