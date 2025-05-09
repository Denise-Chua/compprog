// Problem: B. Apples in Boxes
// Contest: Codeforces Round #1023 (Div. 2)

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

using ll = long long int;

void testcase(int n, int k, vector<int> v){
    int MAX = -1;
    int MIN = 1e9+10;

    int sum = 0;
    int ctr = 0;

    for(int i = 0; i<v.size(); i++){
        sum += v[i];
        MAX = max(MAX, v[i]);
        MIN = min(MIN, v[i]);
    }

    for(int i = 0; i<v.size(); i++){
        if(MAX == v[i]){
            ctr++;
        }
    }

    if(MAX-MIN > k+1 || (MAX-MIN == k+1 && ctr > 1)){
        //cout << "edge\n";
        cout << "Jerry\n";
    }
    else{
        //cout << sum << "\n";
        if(sum%2 == 0){
            cout << "Jerry\n";
        }
        else{
            cout << "Tom\n";
        }
    }


}


int main(){
    int T;
    vector<int> v;
    cin >> T;

    for(int i = 0; i<T; i++){
        v.clear();
        int n;
        int k;
        cin >> n >> k;
        for(int j = 0; j<n; j++){
            int x;
            cin >> x;
            v.push_back(x);
        }

        testcase(n, k, v);
    }
}