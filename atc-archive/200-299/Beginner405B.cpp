//Problem B. Not All
//Contest: AtCoder Beginner Contest 405

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    int m;
    vector<int> v;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    bool all_true = true;

    vector<bool> visited(n+5, false);

    for(int i = 0; i<n; i++){
        visited[v[i]] = true;
        //cout << "setting visited's " << v[i] << " to true\n";

        all_true = true;

        for(int j = 1; j<=m; j++){
            //cout << "checking: " << j << "\n";
            if(visited[j] == false){
                //cout << "non-existing\n";
                all_true = false;
                break;
            }
        }
        //cout << all_true << "\n";
        if(all_true == true){
            cout << n-i << "\n";
            return 0;
        }
    }

    cout << 0 << "\n";

}