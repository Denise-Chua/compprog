
// Problem: B. Vasya's Calendar
// Contest: Codeforces Round #117 (Div. 2)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long int;

int main(){
    int d;
    int n;

    vector<int> v;

    cin >> d >> n;

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    int ans = 0;
    for(int i = 0; i<n-1; i++){
        ans += (-v[i] + d) % d;
        //cout << (-v[i] + d) % d << "\n";
    }

    cout << ans << "\n";



}