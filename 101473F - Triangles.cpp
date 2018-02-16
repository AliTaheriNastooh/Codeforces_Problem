#include <iostream>
#include <map>
using namespace std;
int main(){
  map<int,int> s;
  int n;cin>>n;
  int arr[100000];
  cin>>arr[0];
  s[arr[0]]=1;
  for(int i = 1 ; i < n ; i++){
    cin>>arr[i];
    arr[i]+=arr[i-1];
    s[arr[i]]=1;
  }
  int sum = arr[n-1];
  if(sum %3 != 0){
    cout<<"0";
  }
  else{
    sum/=3;
    int x=0;
    for(int i =0 ; i < n ; i++){
      if(s[arr[i]+sum] && s[arr[i]+2*sum])
        x++;
    }
    cout<<x;
  }
}