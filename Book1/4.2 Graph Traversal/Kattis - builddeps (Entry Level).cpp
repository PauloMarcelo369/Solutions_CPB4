#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

unordered_map<string, vector<string>> G;
unordered_map<string, bool> visited;
vector<string> ans;

void dfs(string ini){
    visited[ini] = true;
    
    for (auto v : G[ini]){
        if (!visited[v]){
            dfs(v);
        }
    }
    
    ans.push_back(ini);
}




int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    cin.ignore();
    while(N--){
        string relation;
        getline(cin, relation);
        stringstream ss(relation);
        
        string arq;
        ss >> arq;
        visited[arq] = false;
        arq.pop_back();
        string dependence;
        while (ss >> dependence){
            visited[dependence] = false;
            G[dependence].push_back(arq);
        }
        
    }
    string modified;
    cin >> modified;
    
    dfs(modified);
    reverse(ans.begin(), ans.end());
    
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}