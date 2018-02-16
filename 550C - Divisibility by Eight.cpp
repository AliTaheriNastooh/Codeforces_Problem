#include <iostream>

using namespace std;
/*
bool  h[10][110][110];
int length;
int arr[102];
bool dyn(int index,int number,int remove){

        for(int k=0;k<length+1;k++){
            h[length+1][0][k]=true;
        }
    for(int i=length;i>0;i--){
        for (int j = 0; j <10 ; ++j) {
            for (int k = length; k >0 ; --k) {
                if(k==i){
                    h[i][j][k]=h[i+1][j][0];
                }
            }
        }
    }
    bool result=false;
    for(int i=length;i>0;i--){
        for(int j=0;j<10;j++){
            result|=(h[i+1][  ((j*10)+arr[i])%8 ][0]);
            for (int k = i; k <length+1 ; ++k) {

                result|=h[i][j][k];
                h[i][j][k]=result;

            }
        }
    }


}
*/
int length;
int arr[102];
bool h[105][10][105];
int tmp[102];
int counter=0;
bool bachtrack(int index,int number,int remove){
    if(index==length+1){
        if(number==0){
            return h[index][number][remove]=false;
        }
        return true;
    }
    if(index==remove){
        return  h[index][number][remove]=bachtrack(index+1,number,0);
    }
    if(h[index][number][remove]) return true;
    if(!bachtrack(index+1,(((number==-1?0:number)*10)+arr[index])%8,0 )){
        tmp[counter++]=arr[index];
        return h[index][number][remove]=false;
    }else{
        h[index][number][remove]=true;
    }

    for (int i = index; i <length+1 ; ++i) {
        if(!bachtrack(index,number,i)){
                if(i!=index){
                    tmp[counter++]=arr[index];

                }
            return h[index][number][remove]=false;
            }
        else{
            h[index][number][i]=true;
        }
    }
    return true;
}
int main() {
    string inp;
    cin>>inp;
    length=inp.length();
    for (int i = 1; i < length+1; ++i) {
        arr[i]=inp[i-1]-'0';
    }
    if(!bachtrack(1,-1,0)) {
        cout<<"YES"<<endl;
        for (int j = counter - 1; j >= 0; --j) {
            cout << tmp[j];
        }
    }
    else{
        cout<<"NO";
    }

    return 0;
}