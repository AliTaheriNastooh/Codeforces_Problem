#include<bits/stdc++.h>  
using namespace std;  
const int maxn = 1000005;  
vector<int>e[maxn];  
int n,m;  
int vis[maxn];  
int d[maxn];  
void bfs()  
{  
    queue<int>q;  
    vis[n]=1;  
    d[n]=0;  
    q.push(n);  
    while (!q.empty())  
    {  
        int u = q.front();  
        q.pop();  
        for (int i = 0;i<e[u].size();i++)  
        {  
            int v = e[u][i];  
            if (!vis[v])  
            {  
                vis[v]=1;  
                q.push(v);  
                d[v]=d[u]+1;  
            }  
        }  
    }  
}  
int main()  
{  
    scanf("%d%d",&n,&m);  
    for (int i = 1;i<=n;i++)  
        for (int j = 1;j<=m;j++)  
        {  
            char c;  
            scanf(" %c",&c);  
            if (c=='#')  
            {  
                e[i].push_back(j+n);  
                e[j+n].push_back(i);  
            }  
        }  
    bfs();  
    if (d[1])  
        printf("%d\n",d[1]);  
    else  
        printf("-1\n");  
} 