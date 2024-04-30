#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector<vector<int>> G;
vector<bool> visited;

void dfs(int ini){
    visited[ini] = true;
    for (auto v : G[ini]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    G.reserve(N);
    G.assign(N, vector<int>());
    visited.reserve(N);
    visited.assign(N, false);
    
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    list<int> lista;
    
    dfs(0);
    for (int i = 1; i < N; i++){
        if (!visited[i]){
            lista.push_back(i+1);
        }
    }
    
    if (lista.empty()){
        cout << "Connected" << endl;
        
    }else {
        for (auto v : lista){
            cout << v << endl;
        }
    }
    
}