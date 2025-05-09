
// Problem: B. Pleasant Pairs
// Contest: Codeforces Round #728 (Div. 2)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long int;

void testcase(ll n, vector<ll> &v){

    vector<pair<ll,ll> > x;

    ll ctr = 0;

    for(int i = 0; i<n; i++){
        pair<ll, ll> p;
        p.first = v[i];
        p.second = i+1;
        x.push_back(p);
    }

    sort(x.begin(), x.end());

   /* for(int i = 0; i<x.size(); i++){
        cout << x[i].first << " " << x[i].second << "\n";
    }*/

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            ll product = x[i].first * x[j].first;
            if(product > 2*n){
                break;
            }

            if(product == x[i].second + x[j].second){
                //cout << "indices: " << x[i].second << " " << x[j].second << "\n";
                ctr++;
            }
        }
    }

    cout << ctr << "\n";
}

int main(){
    ll T;
    vector<ll> v;
    cin >> T;

    for(int i = 0; i<T; i++){
        v.clear();

        ll n;
        cin >> n;

        for(int j = 0; j<n; j++){
            ll x;
            cin >> x;
            v.push_back(x);
        }

        testcase(n,v);
    }
}