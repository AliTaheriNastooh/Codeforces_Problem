#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char card[52][2];
int n,f[53][53][53][53];

bool check(char a[2], char b[2]){
	return a[0]==b[0] || a[1]==b[1];
}

bool dfs(int cur,int a,int b,int c){
	bool res=false;
	if(cur==1) return true;
	if(f[cur][a][b][c]) return false;
	if(check(card[a],card[b]))
	res|=dfs(cur-1,a,c,cur-3);
	if(!res && cur-3 && check(card[a],card[cur-3]))
		res|=dfs(cur-1,b,c,a);
	return !(f[cur][a][b][c]=!res);
}

int main(){
	scanf("%d",&n);
	memset(f,false,sizeof(f));
	for(int i=1;i<=n;i++)
		scanf("%s",&card[i]);
	if(dfs(n,n,n-1,n-2))
		printf("YES\n");
	else printf("NO\n");
	return 0;
}