//Problem B. Two Cakes
//Contest: Educational Codeforces Round 35 (Div. 2)

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    int plates, a, b;
    cin >> plates >> a >> b;

    int maxval = -1;

    for(int i = 1; i<plates; i++){
        if(min((a/i), (b/(plates - i))) > maxval){
            maxval = min((a/i), (b/(plates - i)));
            //cout << "THE MAX HAS BEEN SET!!!!: " << maxval << "\n";
        }
    }
    cout << maxval;
}
