//Problem A. Is it rated?
//Contest: AtCoder Beginner Contest 405

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
 int r; int x;
    cin >> r >> x;

    if(x == 1 && 1600<=r && r<=2999){
        cout << "Yes";
    }
    else if(x==2 && 1200<=r && r<=2399){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}