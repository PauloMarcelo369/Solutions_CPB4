#include <bits/stdc++.h>

using namespace std;

#define MAX 110
#define endl '\n'
#define f first
#define s second

int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

char grid[MAX][MAX];
bool visited[MAX][MAX];

int M, N;

bool isValid(int i, int j){
    return i >= 0 && i < M && j >= 0 && j < N && !visited[i][j] && grid[i][j] != '.';
}

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    
    while(!q.empty()){
        i = q.front().f;
        j = q.front().s;
        q.pop();
        
        for (int k = 0; k < 8; k++){
            int cr = i + dr[k];
            int cc = j + dc[k];
            
            if(isValid(cr, cc)){
                visited[cr][cc] = 1;
                q.push({cr, cc});
            }
        }
    }
    
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> M >> N;
    
    for (int i = 0; i < M; i++) 
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            visited[i][j] = 0;
        }
    
    int cont = 0;
     for (int i = 0; i < M; i++) 
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '#' && !visited[i][j]){
                bfs(i, j);
                cont++;
            }
        }
       
    cout << cont << endl; 
}
