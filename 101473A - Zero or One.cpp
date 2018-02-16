#include <iostream>
using namespace std;

int main()
{
  int a, b, c; cin>>a>>b>>c;
  if(a==b && b==c)
    cout<<"*";
  else if(a==b && c!=a)
    cout<<"C";
  else if(c==b && c!=a)
    cout<<"A";
  else if(a==c && b!=a)
    cout<<"B";
  return 0;
}