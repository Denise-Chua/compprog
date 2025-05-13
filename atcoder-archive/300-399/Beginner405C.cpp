//Problem C. Sum of Product
//Contest: AtCoder Beginner Contest 405

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long int;

int main(){
    ll n;
    vector<ll> v;
    cin >> n;
    ll sum = 0;
    ll p2 = 0;
    for(int i = 0; i<n; i++){
        ll x;
        cin >> x;
        v.push_back(x);

        sum += x;
        p2 += x*x;
    }

    cout << ((sum*sum)/2) - ((p2)/2);


}