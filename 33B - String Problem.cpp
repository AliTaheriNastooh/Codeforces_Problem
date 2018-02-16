#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;



const int M=30;

int array[M][M];

int main()
{
	
	for (int i=0; i<M; i++)
	{
		for (int j=0; j<M; j++)
		{
			array[i][j]=1E+8;
		}
	}
	
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	string s1,s2;
	cin>>s1>>s2;
	
	int n;
	cin>>n;
	
	for (int i=0; i<n; i++)
	{
		char c1,c2;
		int w;
		cin>>c1>>c2>>w;
		if (array[c1-'a'][c2-'a']>w)
		{
			array[c1-'a'][c2-'a']=w;
		}		
		
	}
	for (int i=0; i<26; i++)
	{				
		array[i][i]=0;		
	}
	
	
	for (int k=0; k<26; k++)
	{
		for (int i=0; i<26; i++)
		{
			for (int j=0; j<26; j++)
			{				
				int price=array[i][k]+array[k][j];	
				if (array[i][j]>price)							
				{
					array[i][j]=price;
				}
				
			}
		}
	}
	for (int i=0; i<26; i++)
	{				
		array[i][i]=0;		
	}
	
	/*for (int i=0; i<M; i++)
	{
		for (int j=0; j<M; j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	if (s1.length()!=s2.length())
	{
		cout<<"-1"<<endl;
	}
	else
	{
		int ans=0;
		bool ok=true;
		for (int i=0; i<s1.length(); i++)
		{
			if (s1[i]!=s2[i])
			{
				int min_ans=1E+8;
				int index=-1;
				for (int j=0; j<26; j++)
				{
					if (array[s1[i]-'a'][j]!=1E+8 && array[s2[i]-'a'][j]!=1E+8)
					{
						if (array[s1[i]-'a'][j]+array[s2[i]-'a'][j]<min_ans)
						{
							min_ans=array[s1[i]-'a'][j]+array[s2[i]-'a'][j];
							index=j;
						}
					}
				}
				if (index==-1)
				{
					ok=false;
					break;
				}
				else
				{
					ans=ans+min_ans;
					s1[i]=index+'a';
				}
				
			}
		}
		if (ok==false)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<ans<<endl;
			cout<<s1<<endl;
		}
		
	}
	
		
	return 0;
	
}