#include <iostream>

using namespace std;
int m,n;
int arr[12][6];
int h[12][1005];
int memor(int sufer,int rem){
    if(sufer==m+1){
        return 0;
    }
    if(h[sufer][rem]) return h[sufer][rem];
    int best=0,tmp;
    for (int i = 0; i <=arr[sufer][0]/arr[sufer][1] ; ++i) {
        if (rem - (i * arr[sufer][2]) >= 0) {
            tmp = memor(sufer + 1, rem - (i * arr[sufer][2])) + (i * arr[sufer][3]);
            if (tmp > best) {
                best = tmp;

            }
        }
    }
    return h[sufer][rem]=best;
}

int main() {
    int c0,d0;
    cin>>n>>m>>c0>>d0;
    arr[0][0]=n;
    arr[0][1]=1;
    arr[0][2]=c0;
    arr[0][3]=d0;
    for (int i = 1; i <=m ; ++i) {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
    }
    memor(0,n);
    cout<<h[0][n];
    return 0;
}