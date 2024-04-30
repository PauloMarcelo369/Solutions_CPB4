#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX 10010

vector<vector<int>> G(MAX);
vector<bool> visited(MAX);
vector<bool> up(MAX);

int bfs(int v){
    if (visited[v]) return 0;
    
    queue<int> q;
    q.push(v);
    visited[v] = true;
    up[v] = false;
    int cont = 1;
    
    while(!q.empty()){
        v = q.front();
        q.pop();
        
        for (auto u : G[v]){
            if (!visited[u] && !up[u]){
                visited[u] = true;
                cont++;
                q.push(u);
            }
        }
    }
    return cont;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        G.assign(n, vector<int>());
        visited.assign(n, false);
        up.assign(n, false);
        
        while (m--){
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
        }
        
        queue<int> q;
        
        while(k--){
            int a;
            cin >> a;
            a--;
            q.push(a);
            up[a] = true;
        }
        
        int cont = 0;
        
        while(!q.empty()){
            int v = q.front();
            q.pop();    
            cont += bfs(v);
        }
        
        cout << cont << endl;
    }
}