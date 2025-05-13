//Problem: A. Double Cola
//Contest: Yandex.Algorithm 2011: Qualification 2

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    //bazinga.....

    vector<string> name;
    name.push_back("Sheldon");
    name.push_back("Leonard");
    name.push_back("Penny");
    name.push_back("Rajesh");
    name.push_back("Howard");

    long long int sheldon_num = 1;

    int i = 0;
    while(sheldon_num < n){
        //cout << "Current sheldon num: " << sheldon_num << "\n";
        sheldon_num += pow(2, i) * 5;
        //cout << "Current i: " << i << "\n";
        i++;
        if(sheldon_num >= n){
            break;
        }
    } 

    if(sheldon_num != n){
        sheldon_num -= pow(2, i-1) * 5;
    }

    /*cout << "SHELDON NUMBER: " << sheldon_num << "\n";

    cout << "CURRENT i: " << i << "\n";
*/


    int difference = n - sheldon_num + 1;
    i--;
    int increment = pow(2,i);
    
    /*cout << "DIFFERENCE" << difference << "\n";
    cout << "INCREMENT" << increment << "\n";*/


    for(int j = 0; j<5; j++){
        if(difference <= (j+1)*increment){
            cout << name[j%5];
            break;
        }
    }

    if(n==1){
        cout << "Sheldon";
    }
}