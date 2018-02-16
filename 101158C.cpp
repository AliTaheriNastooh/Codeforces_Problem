#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int comp(pair<int ,int > &a,pair<int ,int > &b){
    return a.first<b.first;
}


int main() {
    int n;cin>>n;
    int m;cin>>m;
    vector<pair<int , int>> arr,arm;

    for(int i=0;i<=n;i++){
        arr.push_back(make_pair(i,i));
    }
    for(int i=0;i<m;i++){
        int x;cin>>x;
        int y;cin>>y;
        arm.push_back(make_pair(x,y));
    }
    sort(arm.begin(),arm.end(),comp);
    for(int i=0;i<arm.size();i++){
        int x=arm[i].first;
        int y=arm[i].second;
        arr[y].second=arr[y+1].second;
        arr[y+1].first=arr[y].first;
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i].second-arr[i].first+1<<" ";
    }
    cout<<endl;
    return 0;
}
close