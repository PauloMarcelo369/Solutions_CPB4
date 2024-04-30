#include <bits/stdc++.h>

using namespace std;

#define MAX 1010
#define INF 0x3f3f3f3f
#define s second
#define f first
#define endl '\n'

int w, h;
char grid[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int dr[] {0, 0, -1, 1};
int dc[] {1, -1, 0, 0};

bool isValid(int i, int j){
    return i >= 0 && i < h && j >= 0 && j < w && !visited[i][j] && grid[i][j] != '#';
}

void fireBfs(vector<pair<int, int>>& sources){
    queue<pair<int, int>> q;
    
    for (auto v : sources){
        q.push(v);
        visited[v.f][v.s] = 1;
        dist[v.f][v.s] = 0;
    }
     
     while(!q.empty()){
        int i = q.front().f;
        int j = q.front().s;
        q.pop();
        
        for (int k = 0; k < 4; k++){
            int cr = i + dr[k];
            int cc = j + dc[k];
            
            if (isValid(cr, cc)){
                visited[cr][cc] = 1;
                dist[cr][cc] = dist[i][j] + 1;
                q.push({cr, cc});
            }
        }
    }
}

int bfs(pair<int, int>& o){
    
    queue<pair<int, int>> q;
    q.push(o);
    visited[o.f][o.s] = 1;
    dist[o.f][o.s] = 0;
    
    while (!q.empty()){
        int i = q.front().f;
        int j = q.front().s;
        q.pop();
        
        if (i == 0 || j == 0 || i == h-1 || j == w-1){
            return dist[i][j] + 1;
        }
        
        for (int k = 0; k < 4; k++){
            int cr = i + dr[k];
            int cc = j + dc[k];
            
            if (isValid(cr, cc) && dist[i][j]+1 < dist[cr][cc]){
                visited[cr][cc] = 1;
                dist[cr][cc] = dist[i][j] + 1;
                q.push({cr, cc});
            }
        }
    }
    
    return -1;
}




int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    
    while(t--){
        cin >> w >> h;
        
        vector<pair<int, int>> sources;
        pair<int, int> o;
        
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                cin >> grid[i][j];
                visited[i][j] = false;
                dist[i][j] = INF;
                if (grid[i][j] == '@') o = {i, j};
                if (grid[i][j] == '*') sources.push_back({i, j});
            }
        }
        
        fireBfs(sources);
        
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                visited[i][j] = 0;
                
        int ans = bfs(o);
        if (ans != -1) cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
}