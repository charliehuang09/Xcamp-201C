#include<bits/stdc++.h>
using namespace std;
void printvect(vector<vector<int>> input){
    for (int i = 0; i < input.size();i++){
        for (int j = 0; j < input[i].size();j++){
            cout << input[i][j] << " ";
        }
        cout << "\n";
    }
}