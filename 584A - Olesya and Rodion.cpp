#include<stdio.h>
#include<string.h>
int main(){
	int x;
	int t;
	//long long int s=0;
	scanf("%d",&x);
	scanf("%d",&t);
	if(x==1 && t==10){
	printf("-1");
	return 0;
	}
	char s[100];
	s[0]=0;
	if(t==10){
	s[0]='1';
	s[1]='0';
	s[2]=0;
	for(int i=0 ; i<x-2 ; i++)
		strcat(s,"0");
	printf("%s",s);
	return 0;
	}
	for(int i=0 ; i<x ; i++)
		strcat(s,"0");
	s[0]='0'+t;
	printf("%s",s);
return 0;
}