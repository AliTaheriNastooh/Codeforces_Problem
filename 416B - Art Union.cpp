#include <iostream>

using namespace std;
int h[50002][6];
int inp[50002][6];
int m,n;
int dyn(){
    for(int i=1;i<=n;i++){
        h[1][i]=h[1][i-1]+inp[1][i];
    }
    for (int i = 2; i <=m; ++i) {
        h[i][1]=h[i-1][1]+inp[i][1];
    }
    for (int j = 2; j <=n ; ++j) {
        for (int i = 2; i <=m ; ++i) {
            h[i][j]=(max(h[i-1][j],h[i][j-1]))+inp[i][j];
        }
    }
}
int main() {
    cin>>m>>n;
    for (int i = 1; i <=m ; ++i) {
        for(int j=1;j<=n;j++){
            cin>>inp[i][j];
        }
    }
    dyn();
    for (int k = 1; k <=m ; ++k) {
        cout<<h[k][n]<<" ";
    }
    return 0;
}