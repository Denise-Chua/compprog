// Problem: A. Strong Password
// Contest: Educational Codeforces Round #168 (Div. 2)

#include <iostream>

using namespace std;

using ll = long long int;

char after(char x){
    int result = x;
    result += 1;
    char ans = result;

    if(x == 'z'){
        return 'a';
    }
    else{
        return ans;
    }
}

void testcase(string s){
    string answer = "";

    if(s.size() == 1){
        answer += after(s[0]);
        answer += s[0];
        cout << answer << "\n";
        return;
    }
    else{
        answer += s[0];
        int ctr = 0;

        for(int i = 1; i<s.size(); i++){
            if(s[i] == s[i-1] && ctr == 0){
                answer += after(s[i]);
                answer += s[i];
                ctr++;
            }
            else{
                answer += s[i];
            }
        }

        if(ctr == 0){
            answer += after(s[s.size()-1]);
        }
    }

    cout << answer << "\n";
    return;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i<T; i++){
        string s;
        cin >> s;
        testcase(s);
    }
}