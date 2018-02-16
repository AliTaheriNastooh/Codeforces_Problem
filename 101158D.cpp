#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull B=5575777;
int K;
  
int n,m;
char a[5000];
char b[5000];
ull po[5000];
 
int main(){
  po[0]=1;
  for(int i=1;i<500;i++)po[i]=po[i-1]*B;
    
  scanf("%s %s",a,b);
  n=strlen(a);
  m=strlen(b);
  
  int ans=0;
  for(int K=1;K<=min(n,m);K++){
 
    set< ull > st;
    ull key,d;
      
    key=0,d=1;
    for(int i=0;i<n;i++){
      key+= po[ (int)a[i] ];
      if(i-K>=0){
        key-= po[ (int)a[i-K] ];
      }else d*=B;
      if(i>=K-1)st.insert(key);
    }
      
    key=0,d=1;
    for(int i=0;i<m;i++){
      key+= po[ (int)b[i] ];
      if(i-K>=0){
        key-= po[ (int)b[i-K] ];
      }else d*=B;
       
      if(i>=K-1)
        if( st.count(key)>0 )
          ans=K;
    }
      
  }
  printf("%d\n",ans);
  return 0;
}