
 #include <iostream>
using namespace std;

int main()
{
  int n, m; cin>>n>>m;
  bool arr[10001];
  for(int i=0;i<10000;i++)
    arr[i]=false;
  for(int i=0;i<m;i++)
  {
    int a; cin>>a;
    arr[a-1] = true;
  }
  int f=1;
  for(int i=0;i<n;i++)
    if(!arr[i])
    {
      cout<<i+1<<" ";
      f=0;
    }
  if(f)
    cout<<"*";
  return 0;
}