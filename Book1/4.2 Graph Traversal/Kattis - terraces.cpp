#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define endl '\n'

int x, y;

int grid[500][500];
bool visited[500][500];

int dc[] = {0, 0, -1, 1};
int dr[] = {1, -1, 0, 0};

int bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    int number = grid[i][j];
    
    int cont = 0;
    while(!q.empty()){
        i = q.front().f;
        j = q.front().s;
        q.pop();
        
        if (cont != -1) {
            cont++;
        }
        
        
        for (int k = 0; k < 4; k++){
            int cc = j + dc[k];
            int cr = i + dr[k];
            
            if (cc >= 0 && cc < x && cr >= 0 && cr < y && !visited[cr][cc]){
                if (grid[cr][cc] == number){
                    q.push({cr, cc});
                    visited[cr][cc] = true;
                }
                else if (grid[cr][cc] < number){cont = -1; continue;}
                else if(grid[cr][cc] > number) bfs(cr, cc);
            }
        }
    }
    
    return cont != -1 ? cont : 0;
}

int main(){
    cin >> x >> y;
    
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++){
            cin >> grid[i][j];
            visited[i][j] = false;
            
        }
            
            
    int ans = 0;
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++){
            if (!visited[i][j]){
                ans += bfs(i, j);
            }
        }
    
    cout << ans << endl;
}