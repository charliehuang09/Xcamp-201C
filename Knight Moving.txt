/******************************************************************************
 
2021-fa-201-wk9-bfs-path-step
 
*******************************************************************************/
#include<bits/stdc++.h>
#include <queue>
using namespace std;
 
int dx[8] = { -2, -1, 1, 2,  2,  1, -2, -1};
int dy[8] = {  1,  2, 2, 1, -1, -2, -1, -2};
 
struct PNT { // define struct to push to queue
    int x, y;
    PNT (int x0, int y0) : x(x0), y(y0){};
};
int main(int argc, const char * argv[]) {
    queue<PNT> q;
    int size,sx,sy,ex,ey;
    cin >> size >> sy >> sx >> ey >> ex;
    int visited[size][size];
    int dist[size][size];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            visited[i][j] = 0;
            dist[i][j] = 0;
        }
    }
     
    visited[sx][sy] = 1;
    q.push(PNT(sx,sy));
     
    while(!q.empty()) {
        PNT pt = q.front();
        q.pop(); // remove front
         
        for(int i = 0; i < 8; i++) {
            int nx = pt.x + dx[i];
            int ny = pt.y + dy[i];
 
            if (nx >= 0 && nx < size && ny >= 0 && ny < size && visited[nx][ny] == 0) { // can move
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[pt.x][pt.y] + 1; // shortest path to this pos
                if (nx == ex && ny == ey) {
                    cout << dist[nx][ny]; // we are at end point
                    return 0;
                }
                q.push(PNT(nx, ny));
            }
        }
    }
     
    cout << "No solution"; // if can't reach end point
}
/*
10
3 6
1 9
 
3
*/