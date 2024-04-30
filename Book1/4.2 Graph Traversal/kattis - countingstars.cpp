#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAX 100

int dc[] = {0, 0, 1, -1};
int dr[] = {1, -1,  0, 0};

int M, N;

char grid[MAX][MAX];
bool visited[MAX][MAX];

bool isValid(int i, int j){
    return i >= 0 && i < M && j >= 0 && j < N && !visited[i][j] && grid[i][j] != '#';
}


void bfs(int i, int j){
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    
    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        q.pop();
        
        for (int k = 0; k < 4; k++) {
            int di = i + dr[k];
            int dj = j + dc[k];
            
            if(isValid(di, dj)){
                visited[di][dj] = true;
                q.push({di, dj});
            }
        }
    }
    
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int c = 1;
    while (cin >> M >> N){
        for (int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cin >> grid[i][j];
                visited[i][j] = false;
            }
        }
        
        int cont = 0;
        for (int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if (grid[i][j] == '-' && !visited[i][j]){
                    bfs(i, j);
                    cont++;
                }
            }
        }
        
        cout << "CASE " << c << ": " << cont << endl;
        c++;
    }
}