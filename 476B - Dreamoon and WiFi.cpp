#include <iostream>

using namespace std;

string s2;
int h[30][30];
double power(int exp){
    double result=1;
    while (exp){
        result *=2;
        exp--;
    }
    return result;
}
double dyn(int pos,int length){
    /*
    for(int j=0;j<2*length+2;j++){
        h[length][j]=-1;
    }
     */
    //length++;
    if(pos>=0){
        pos=pos+15;
    }else{
        pos=15-(-pos);
    }
    h[length][pos]=1;

    h[length][pos]=1;
    int counter=0;
    for(int i=length-1;i>=0;i--){
        for (int j = 15-length; j <=15+length ; ++j) {
            if (s2[i] == '?') {
                h[i][j] = h[i + 1][j + 1] + h[i + 1][j - 1];

            }
            else{
                if(s2[i]=='+'){
                    h[i][j]=h[i+1][j+1];
                }else{
                    h[i][j]=h[i+1][j-1];
                }
            }
        }
        if(s2[i]=='?'){
            counter++;
        }
    }

        return (h[0][15 ]) / power(counter);



}
int main() {
    string s1;
    cin>>s1>>s2;
    int counter=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]=='+')
            counter++;
        else
            counter--;
    }

    printf("%.12lf",dyn(counter,s1.length()));
    return 0;
}