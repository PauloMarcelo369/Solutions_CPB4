#include <bits/stdc++.h>

using namespace std;

#define MAX 100
#define endl '\n'

vector<vector<int>> G(MAX);
vector<bool> visited(MAX);

void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source] = true;
    
    while (!q.empty()){
        int u = q.front();
        q.pop();
        
        for (auto v : G[u]){
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int C;
    cin >> C;
    while(C--){
        int N;
        cin >> N;
        
        G.assign(N, vector<int>());
        visited.assign(N, false);
        
        int R;
        cin >> R;
        
        for (int i = 0; i < R; i++){
            int a, b;
            cin >> a >> b;
            
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        int cont = 0;
        
        for (int i = 0; i < N; i++){
            if (!visited[i]){
                cont++;
                bfs(i);
            }
        }
        
        cout << cont-1 << endl;
    }
}