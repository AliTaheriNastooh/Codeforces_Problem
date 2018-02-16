#include <iostream>
#define modd 1000000007
using namespace std;
long long int k;
long long int h[1000003];

long long int rec(long long int n){
    if(n<k) return 1;
    if(h[n]!=0)return h[n];
    return h[n]=(rec(n-1)%modd+rec(n-k)%modd)%modd;
}

int main() {
    for(int i=0;i<100003;i++){
        h[i]=0;
    }
    long long int answer=0;
    int t,a,b;




    cin>>t>>k;
    for(int i = 0  ; i < k ; i++) h[i] = 1;
   rec(100002);
//    for(int i = 0  ; i <= k ; i++) h[i] = 1;
//    for(int i = k ; i < 100003 ; i++){
//        h[i] = (h[i-1]%modd + h[i - k]%modd)%modd;
//    }
    long long acc=0;
//    for(int i=0; i<100003;i++){
//        acc=(acc+h[i])%modd;
//        h[i]=acc;
//    }
    for(int i = 1 ; i < 100003 ; i++){
        h[i] = (h[i]+h[i-1])%modd;
    }
    //for(int i = 0 ; i < 100 ; cout<<h[i++]<<endl);
    for(int i=0; i < t ; i++){
        cin>>a>>b;
        answer=(h[b]%modd - h[a-1]%modd)%modd;
        answer=(answer<0)? modd+answer  : answer;
        cout<<answer<<endl;
    }
    return 0;
}