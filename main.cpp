#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct coord{
    int x;
    int y;
    int z;
};
int dy[3] = {0,1,-1};
int dx[3] = {0,1,-1};
int dz[3] = {0,1,-1};
vector<vector<vector<int>>> board;
vector<vector<vector<int>>> visited;
vector<vector<vector<int>>> dist;

void printboard(){
    cout << "\n\n";
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            for (int k = 0; k < board[i][j].size(); k++){
                cout << visited[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n\n";
    }
    cout << "\n\n";
    return;
}

bool inbound(int y, int z, int x){
    try{
        board[y][z][x];
        return true;
        throw 69;
    }
    catch(int x){
        return false;
    }
}
int solve(){
    board.clear();
    int x,y,z,time_limit;
    cin >> y >> z >> x >> time_limit;
    vector<vector<int>> tempa;
    vector<int> tempb;
    int tempc;
    for (int i = 0; i < y; i++){
        tempa.clear();
        for (int j = 0; j < z; j++){
            tempb.clear();
            for (int k = 0; k < x; k++){
                tempb.push_back(0);
            }
            tempa.push_back(tempb);
        }
        visited.push_back(tempa);
        dist.push_back(tempa);
    }
    for (int i = 0; i < y; i++){
        tempa.clear();
        for (int j = 0; j < z; j++){
            tempb.clear();
            for (int k = 0; k < x; k++){
                cin >> tempc;
                tempb.push_back(tempc);
            }
            tempa.push_back(tempb);
        }
        board.push_back(tempa);
    }
    queue<coord> q;
    coord point;
    coord tempd;
    tempd.x = 0;
    tempd.y = 0;
    tempd.z = 0;
    q.push(tempd);
    while (!q.empty()){
        point = q.front();
        q.pop();
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    cout << "D";
                    if (i + j + k != 0){
                        cout << "D???";
                        if (inbound(point.y + dy[i], point.z + dz[j], point.x + dx[k]) == true){
                            cout << "a";
                            coord nextpoint;
                            nextpoint.x = point.x + dx[k];
                            nextpoint.y = point.y + dy[i];
                            nextpoint.z = point.z + dz[j];
                            if (visited[nextpoint.y][nextpoint.z][nextpoint.x] == 0){
                                dist[nextpoint.y][nextpoint.z][nextpoint.x] = dist[point.y][point.z][point.x];
                                visited[nextpoint.y][nextpoint.z][nextpoint.x] = 1;
                                coord temp;
                                q.push(nextpoint);
                                cout << "D";
                            }   
                        }
                    }
                }
            }
        }
    }
    printboard();



    return dist[dist.size() - 1][dist[0].size() - 1][dist[0][0].size() - 1];

}
int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        cout << solve();
    }
}
/*
1
3 3 4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0
*/