#include <bits/stdc++.h>
using namespace std;

int n,m,r,c;
int A[2000][2000];
int d[2000][2000];  // use to calculate distance moved from start node.
typedef pair<int,int> Coordinates;
queue<Coordinates> q;

// Neighbors
int nx[] = {-1,0,1,0};
int ny[] = {0,-1,0,1};

void input(){
    cin >> n >> m >> r >> c;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> A[i][j];
        }
}

int maze(){
    d[r-1][c-1] = 0;
    A[r-1][c-1] = 1; // block reverse path
    q.push(Coordinates(r-1,c-1));
    while(!q.empty()){
        Coordinates node = q.front();
        q.pop();
        int x0 = node.first;
        int y0 = node.second;
        for(int i=0; i<4; i++){
            int x = x0 + nx[i];
            int y = y0 + ny[i];
            if(x<0 || y<0 || x>=n || y>=m){
                return d[x0][y0] + 1;
                q.pop();
            }
            if(!A[x][y]){
                d[x][y] = d[x0][y0] + 1;    
                q.push(Coordinates(x, y));
                A[x][y] = 1;    // block reverse path
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << maze();
    return 0;
}