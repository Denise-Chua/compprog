//Problem D. Right Left Wrong
//Contest: Codeforces Round 996 (Div. 3)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long int;


vector<ll> answers;

ll sum_of(vector<ll> &Ai, vector<ll> &prefix, int l, int r){
    if(l == r){
        return Ai[l];
    }
    else{
        return abs(prefix[r+1] - prefix[l]);
    }
}


bool l_then_r(vector<char> &Si, int l, int r){
    if(Si[l] == 'L' && Si[r] == 'R'){
        return true;
    }
    else{
        return false;
    }
}


void testcase(int n, vector<ll> &Ai, vector<char> &Si){
    //build a prefix sum array surely
    vector<ll> prefix;
    prefix.push_back(0);

    ll sum = 0;

    for(int i = 0; i<n; i++){
        sum += Ai[i];
        prefix.push_back(sum);
        //cout << prefix[i] << " ";
    }
    //cout << "\n";
    int l = 0;
    int r = n-1;

    ll ans = 0;

    while(l < r){
       // cout << l << " " << r << "\n";
        while((Si[l] == 'R') && (l < n)){
            //cout << "increasing l\n";
            l++;
        }
        while((Si[r] == 'L') && (r >= 0)){
            //cout << "decreasing r\n";
            r--;
        }
        if(l < r){
            ans += sum_of(Ai, prefix, l, r);
            //cout << "closer both\n";
            l++;
            r--;
        }
        /*if(l_then_r(Si, l, r)){
            ans += sum_of(Ai, prefix, l, r);
        }
        else if(l_then_r(Si, l+1, r-1)){
            ans += sum_of(Ai, prefix, l+1, r-1);
            l++;
            r--;
        }
        else if(l_then_r(Si, l+1, r)){
            ans += sum_of(Ai, prefix, l+1, r);
            l++;
        }
        else if(l_then_r(Si, l, r-1)){
            ans += sum_of(Ai, prefix, l, r-1);
            r--;
        }
        else{
            l++;
            r--;
        }*/
    }

    answers.push_back(ans);

}




int main(){
    ll T;
    cin >> T;

    for(int i = 0; i<T; i++){
        ll n;
        cin >> n;

        vector<ll> Ai;
        vector<char> Si;

        for(int j = 0; j<n; j++){
            ll x;
            cin >> x;
            Ai.push_back(x);
        }

        string s;
        cin >> s;

        for(int l = 0; l<n; l++){
            Si.push_back(s[l]);
        }

        testcase(n, Ai, Si);

        Ai.clear();
        Si.clear();
    }

    for(int i = 0; i<answers.size(); i++){
        cout << answers[i] << "\n";
    }
}  