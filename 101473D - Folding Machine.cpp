#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int M;
int N;
vector<int > arr,tmp,out,arr1;

bool rec(vector<int > &num){
    // for(auto i:num){
    //     cout<<i<<" ";
    // }
    cout<<endl;
    if(num.size()<M)return false;
    if(num.size()==M){
        int i=0;
        for(i=0;i<M;i++){
            if(num[i]!=out[i])break;
        }
        if(i==M)return true;
        if(M==N){
            int j=0,k=M-1;
            for(j=0;j<M;j++){
                if(num[j]!=out[k--])break;

            }
            if(j==M)return true;
        }
        return false;
    }
    int end,first;
    for(int i=1;i<num.size();i++){
        if(2*i>=num.size()){
            end=num.size()-1;
            first=i-(end-i+1);
        }else{
            first=0;
            end=(2*i)-1;
        }
        tmp.clear();
        if(first==0){
            for(int j=num.size()-1;j>end;j--){
                tmp.pb(num[j]);
            }
            while(first<end){
                tmp.pb(num[first]+num[end]);
                end--;
                first++;
            }
        }else{
            for(int j=0;j<first;j++){
                tmp.pb(num[j]);
            }

            while(first<end){
                tmp.pb(num[first]+num[end]);
                end--;
                first++;
            }
        }
        arr1.assign(tmp.begin(),tmp.end());
        if(rec(arr1)==true){
            return true;
        }
    }
    return false;
}
int main() {
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;cin>>tmp;
        arr.pb(tmp);
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int tmp;cin>>tmp;
        out.pb(tmp);
    }
    if(rec(arr)){
        cout<<"S";
    }else{
        cout<<"N";
    }
    return 0;
}