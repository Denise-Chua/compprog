//Problem B. Penchick and Satay Sticks
//Contest: Codeforces Round 987 (Div. 2)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calculate(int &n, vector<int> &satay){
    int changes = 1;
    int temp;

    while(changes > 0){
        changes = 0;
        for(int i = 0; i<n-1; i++){
            if(abs(satay[i] - satay[i+1]) == 1 && satay[i+1] < satay[i]){
                //cout << "HAPPENED\n";
                changes++;
                temp = satay[i];
                satay[i] = satay[i+1];
                satay[i+1] = temp;
            }
        }

        if(changes == 0){
            break;
        }

        /*for(int i = 0; i<n; i++){
        cout << satay[i] << "\t";
        }*/
    }

    //nothing changed in the list
    bool decreasing = false;
    for(int i = 0; i<n-1; i++){
        if(satay[i] > satay[i+1]){
            //cout << "OMG DECREASING DETECTED BAD!: " << satay[i] << " " << satay[i+1] << "\n";
            decreasing = true;
            break;
        }
    }

    /*for(int i = 0; i<n; i++){
        cout << satay[i] << "\t";
    }*/

    if(decreasing == true){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }

}



int main(){
    int T;
    cin >> T;
    vector<int> satay;
    for(int i = 0; i<T; i++){
        int n;
        cin >> n;
        satay.clear();
        for(int j = 0; j<n; j++){
            int x;
            cin >> x;
            satay.push_back(x);
        }
        calculate(n, satay);

    }
}