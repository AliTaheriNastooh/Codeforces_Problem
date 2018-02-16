#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF ((1<<29)+123)
#define LL_INF ((1LL<<60)+123)

bool vis[1001];
int N, M, x, y, v[1001][2];
ll dist[1001][1001], c[1001];
vector<pair<int, int> > adj[1001];
priority_queue<pair<int, int> > pq;


void dijkstra(int s) {

    memset(dist[s], -1, sizeof(dist[s]));
    memset(vis, false, sizeof(vis));

    dist[s][s] = 0;
    pq.push(make_pair(0, s));

    while (pq.size()) {
        int cur = pq.top().second;
        pq.pop();

        if (vis[cur]) continue;
        vis[cur] = true;

        for (int i = 0; i < (int) adj[cur].size(); i++) {
            int nxt = adj[cur][i].second;
            int w = adj[cur][i].first;

            if (dist[s][cur]+w < dist[s][nxt] || dist[s][nxt]<0)
                pq.push(make_pair(-(dist[s][nxt]=dist[s][cur]+w), nxt));
        }
    }
}

int main()
{
    if (fopen("data.in", "r"))
        freopen("data.in", "r", stdin);

    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &x);
    scanf("%d", &y);

    x--; y--;
    for (int i = 0; i < M; i++) {
        int a, b, w;
        scanf("%d", &a); a--;
        scanf("%d", &b); b--;
        scanf("%d", &w);

        adj[a].push_back(make_pair(w, b));
        adj[b].push_back(make_pair(w, a));
    }

    for (int i = 0; i < N; i++) dijkstra(i);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i][0]);
        scanf("%d", &v[i][1]);
    }

    memset(c, -1, sizeof(c));
    memset(vis, false, sizeof(vis));

    c[x] = 0;
    pq.push(make_pair(0, x));

    while (pq.size()) {
        int cur = pq.top().second;
        pq.pop();

        if (vis[cur]) continue;
        vis[cur] = true;

        for (int i = 0; i < N; i++)
            if ((c[cur]+v[cur][1]<c[i] || c[i]<0) && dist[cur][i]<=v[cur][0] && dist[cur][i]>0)
                pq.push(make_pair(-(c[i]=c[cur]+v[cur][1]), i));
    }

    printf("%I64d\n", c[y]);
    return 0;
}