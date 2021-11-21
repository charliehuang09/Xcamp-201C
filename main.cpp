#include<bits/stdc++.h>
using namespace std;
struct PNT { // define struct to push to queue
	int x, y;
	PNT (int x0, int y0) : x(x0), y(y0){};
};

vector<string> maze;
int colm, row;
PNT portal(PNT point, char portal){//find portal
    for (int i = 0; i < colm; i++){//intialize 0
        for (int j = 0; j < row; j++){
            if (i == point.x && j == point.y){

            }
            else{
                if (maze[i][j] == portal){
                    return PNT(i,j);
                }
            }
        }
    }
}
int main() {
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    cin >> colm >> row;
    string temp;
    for (int i = 0; i < colm; i++){
        cin >> temp;
        maze.push_back(temp);
    }  
    int visited[colm][row];
    int ways[colm][row];
    int dist[colm][row];
    for (int i = 0; i < colm; i++){//intialize 0
        for (int j = 0; j < row; j++){
            visited[i][j] = 0;
            ways[i][j] = 0;
            dist[i][j] = 0;
        }
    }
    queue<PNT> q;
    visited[0][0] = 1;
    ways[0][0] = 1;
    q.push(PNT(0,0));
    
    while(!q.empty()) {
        PNT pt = q.front();
        q.pop(); // remove front
        for(int i = 0; i < 4; i++) {
            int nx = pt.x + dx[i];
            int ny = pt.y + dy[i];
            if (nx >= 0 && nx < colm && ny >= 0 && ny < row && maze[nx][ny] != '1') { // can move, no need to check visited
                if (maze[nx][ny] != '0'){
                    PNT temp2 = portal(PNT(nx,ny), maze[nx][ny]); 
                    nx = temp2.x;
                    ny = temp2.y;
                    //cout << nx << " " << ny << "\n";
                }
                if (visited[nx][ny] == 0) { // first time to be here
                    dist[nx][ny] = dist[pt.x][pt.y] + 1; // shortest path to this pos 
                    ways[nx][ny] = ways[pt.x][pt.y];
                    visited[nx][ny] = 1;
                    q.push(PNT(nx, ny));
                }
                else if (dist[nx][ny] == dist[pt.x][pt.y] + 1) 
                    ways[nx][ny] += ways[pt.x][pt.y]; // need to add new ways
            }
        }
    }
    if (dist[colm - 1][row - 1] == 0){
        cout << "No Solution.";
        return 0;
    }
    cout << dist[colm - 1][row - 1]; // ways to end point
}
