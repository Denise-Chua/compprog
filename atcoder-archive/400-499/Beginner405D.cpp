//Problem D. Escape Route
//Contest: AtCoder Beginner Contest 405

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <iomanip>
#include <queue>

using namespace std;
using ll = long long int;

int main(){
    int H;
    int W;
    cin >> H >> W;
    vector<string> v;
    vector<vector<int> > dist(H, vector<int>(W, -1));
    vector<vector<char> > ans(H, vector<char>(W, -1));
    vector<vector<pair<int, int> > > parent(H, vector<pair<int, int> >(W, {-1, -1}));

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char arrow[4] = {'^','v','<','>'};

    queue<pair<int, int > > q;

    for(int i = 0; i<H; i++){
        string s;
        cin >> s;
        v.push_back(s);
        for(int j = 0; j<s.size(); j++){
            if(s[j] == 'E'){
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        pair<int, int> c = q.front();

        int x = c.first;
        int y = c.second;

        q.pop();

        for(int d = 0; d<4; d++){
            int next_x = x + dx[d];
            int next_y = y + dy[d];

            if(next_x>=0 && next_y >= 0 && next_x<H && next_y<W){
                //within boun :)

                //cout << "within bound: " << next_x << " " << next_y << "\n";

                if(v[next_x][next_y] == '.' && dist[next_x][next_y] == -1){
                    dist[next_x][next_y] = dist[x][y] + 1;
                    parent[next_x][next_y] = c;
                    q.push({next_x, next_y}); 
                }
            }
        }
    }

    for(int i = 0; i<H; i++){
        for(int j = 0; j < W; j++){
            if(v[i][j] != '.'){
                continue;
            }
            pair<int, int> p = parent[i][j];
            for(int d = 0; d<4; d++){
                if(dx[d]+i == p.first && dy[d]+j == p.second){
                    ans[i][j] = arrow[d];
                }
            }
        }
    }

    for(int i = 0; i<H; i++){
        for(int j = 0; j<W; j++){
            //cout <<  "(" << parent[i][j].first << "," << parent[i][j].second << ") ";
            if(ans[i][j] == '^' || ans[i][j] == '<' || ans[i][j] == '>' || ans[i][j] == 'v'){
                cout << ans[i][j];
            }
            else{
                cout << v[i][j];
            }
        }
        cout << "\n";
    }


}