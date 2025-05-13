//Problem: A. Eating Soup
//Contest: Codeforces Round 558 (Div. 2)

#include <iostream>

using namespace std;

int main(){
    float total;
    int removed;
    cin >> total >> removed;

    if(removed == 0){
        cout << 1;
    }
    else if (removed == total){
        cout << 0;
    }
    else{
        if(removed > total/2){
            cout << total - removed;
        }
        else{
            cout << removed;
        }

    }
}