#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int arr[10][10];

string my_check(string  a){
    int i=0,j,res;
    for(int k=0;k<4;k++){
        j=a[k]-'0';
        res=arr[i][j];
        i=res;
    }
    char t=(res+'0');
    string tmp=a+t;
    return tmp;
}

int check_error(string s){
    int i=0,j;
    int res = 0;
    for(int k=0;k<5;k++){
        j=s[k]-'0';
        res=arr[i][j];
        i=res;
    }
    //cout<<res;
    return res;
}

int main(){
    for (int i = 0; i < 10; ++i)
    {
        /* code */
        for (int j = 0; j < 10; ++j)
        {
            cin>>arr[i][j];
        }
    }
    long long int cnt=0;
    for(int i=0;i<10000;i++){

        bool f1=false;
        stringstream ss;
        ss<<setw(4)<<setfill('0')<<i;
        string s=ss.str();
        s=my_check(s);
       // cout<<i<<"  "<<s<<endl;
        for(int j=0;j<4;j++){
         //   cout<<s<<" ";
            if(s[j]!=s[j+1]) {
                swap(s[j], s[j + 1]);
                // cout<<s<<endl;
                if (check_error(s)==0) {
                  f1=true;
                   // break;
                }
                swap(s[j], s[j + 1]);
            }
        }
       // cout<<cnt;
        for(int j=0;j<5;j++){
            int dig=s[j]-'0';
            string s2=s;
            for(int k=0;k<10;k++){
                if(k!=dig){
                    s2[j]=(char)(k+'0');
                    //cout<<s2<<endl;
                    if(check_error(s2)==0){
                        f1=true;
                        break;
                    }
                }
            }
        }
        if(f1){
            cnt++;
        }

    }
    cout<<cnt;
    return 0;
}