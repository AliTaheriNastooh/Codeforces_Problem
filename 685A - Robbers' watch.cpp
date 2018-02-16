#include <iostream>
using namespace std;


int main(){
	int n,m,x=1,y=1,s=0,a,z,k,b;
    cin>>n>>m;
    for(int a=7;a<n;a*=7){x++;}
    for(int b=7;b<m;b*=7){y++;}
    if(x+y<=7){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                z=0;
                int v[7]={0};
                a=i;
                for (k=0;k<x;k++){v[a%7]+=1;a/=7;}
                b=j;
                for (k=0;k<y;k++){v[b%7]+=1;b/=7;}
                for(z=0;z<=6;z++){ if(v[z]>1)break;}
                if(z==7){s++;}
            }
        }
    }
    cout<<s;
}