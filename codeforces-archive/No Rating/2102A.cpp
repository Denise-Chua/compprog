//Problem A. Dinner Time
//Contest: Codeforces Round 1024 (Div. 2)

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;

void testcase(int n, int m, int p, int q){
    //n is number of all elements
    //m is the SUM of all elements

    //p is the number of consec
    //q is the sum of consec

    int val = (n/p) * q;

    int rem = n%p;

    if(rem == 0){
        if(m == val){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    else{
        cout << "YES\n";
    }

}


int main(){
    int t;
    cin >> t;
    for(int i =0 ; i<t; i++){
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        testcase(n,m,p,q);
    }
}
