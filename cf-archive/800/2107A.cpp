// Problem: A. LRC and VIP
// Contest: Codeforces Round #1023 (Div. 2)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long int;


int gcd(int a, int b) {
    int res = min(a, b);

    while (res > 1) {
        if (a % res == 0 && b % res == 0)
            break;
        res--;
    }
	return res;
}

void testcase(int x, vector<int> v){
    int g = v[0];

    vector<int> p;
    vector<int> s;

    for(int i = 0; i<x; i++){
        g = gcd(g, v[i]);
        p.push_back(g);
    }  

    //cout << g << "\n";

    if(g > 1){
        cout << "No\n";
        return;
    }
    
    g = v[x-1];

    for(int i = x-1; i>=0; i--){
        g = gcd(g, v[i]);
        s.push_back(g);
    }  

    

    reverse(s.begin(), s.end());

    /*cout << "---\n";
    for(int i = 0; i<p.size(); i++){
        cout << p[i] << "\n";
        cout << s[i] << "\n";
        cout << "---\n";
    }*/

    int ans = 0;
    int index = 0;
    for(int i = 0; i<x; i++){
        if(i == 0){
            ans = s[1];
        }
        else if(i == x-1){
            ans = p[p.size()-2];
        }
        else{
            ans = gcd(p[i-1], s[i+1]);
        }

        //cout << ans << " " << v[i] << "\n";

        if(ans != v[i]){
            //cout << "*: " << index << "\n";
            index = i;
            break;
        }
    }
    cout << "Yes\n";
    for(int i = 0; i<x; i++){
        if(i == index){
            cout << "1 ";
        }
        else{
            cout << "2 ";
        }
    }
    cout << "\n";
    return;
}

int main(){
    int T;
    vector<int> v;
    cin >> T;

    for(int i = 0; i<T; i++){
        v.clear();

       int x;
       cin >> x;

       for(int j = 0; j<x; j++){
            int y;
            cin >> y;
            v.push_back(y);
       } 

       testcase(x,v);
    }
}