#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int M, N;

int dc[] {1, -1, 0, 0, -1, 1, 1, -1};
int dr[] {0, 0, -1, 1, 1, 1, -1, -1};

char grid[100][100];
bool visited[100][100];

bool correct(int i, int j){
    return i >= 0 && i < M && j >= 0 && j < N && grid[i][j] == '@';
}

void bfs(int i, int j){
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    
    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for (int k = 0; k < 8; k++){
            int cr = r + dr[k];
            int cc = c + dc[k];
            if (correct(cr, cc) && !visited[cr][cc]){
                visited[cr][cc] = true;
                q.push({cr, cc});
            }
        }
    }
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> M >> N){
        if (!M) break;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                cin >> grid[i][j];
                visited[i][j] = false;
            }
        }
        
        int cont = 0;
        
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if (grid[i][j] == '@' && !visited[i][j]){
                    cont++;
                    bfs(i, j);
                }
            }
        }
        cout << cont << endl;
    }
    
}