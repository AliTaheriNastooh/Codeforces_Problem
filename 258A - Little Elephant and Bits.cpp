#include<stdio.h>
#include<string.h>
#include<string.h>
int main(){
	char s[100001];
	scanf("%s",s);
	int flag=0;
	for(int i=0 ; s[i] != 0 ;i++){
		if(flag==0 && s[i+1]==0){
		break;
		}
		if(flag==0){
		if(s[i]!='0')
			printf("%c",s[i]);
		else
			flag=1;
		}
		else
			printf("%c",s[i]);

	
	}
return 0;
}