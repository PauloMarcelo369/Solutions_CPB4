#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void dfs(char source, unordered_map<char, vector<char>>& G,  unordered_map<char, bool>& visited){
    visited[source] = true;
    for (auto v : G[source]){
        if (!visited[v]){
            dfs(v, G, visited);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;

    while (N--){
        unordered_map<char, vector<char>> G;
        unordered_map<char, bool> visited;
        char maximum;
        cin >> maximum;
        cin.ignore();
        string a;
        while(getline(cin, a) && a != ""){
            G[a[0]].push_back(a[1]);
            G[a[1]].push_back(a[0]);
        }

        int cont = 0;

        for (auto s : G){
            if (!visited[s.first]){
                cont++;
                dfs(s.first, G, visited);
            }
        }
        cout << cont << endl;
        if (N) cout << endl;
    }    
}