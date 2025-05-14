#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long int;

ll delivery(int N, int K, int L, int v[]){

    //N is the number of teams that need their gifts
    //K is the carrying capacity
    //L is the number of nodes (ex. L = 8 gives us: 0,1,2,3,4,5,6,7)

    //v[] is an array

    vector<int> team_pos;
    team_pos.push_back(-1);
    for(int i = 0; i<N; i++){
        team_pos.push_back(v[i]);
    }

    vector<ll> cw(N+5, -1);
    vector<ll> ccw(N+5, -1);

    cw[0] = 0;
    ccw[0] = 0;

    sort(team_pos.begin(), team_pos.end());

    //----- ACCOUNT FOR DEFAULT FIRST
    //cw[i] = minimum total distance to DELIVER FIRST i GIFTS via CW
    //ccw[i] = minimum total distance to DELIVER FIRST i GITS via CCW
   for(int i = 1; i<=N; i++){
        cw[i] = 2*team_pos[i];
        ccw[i] = 2 * (L - team_pos[N - i + 1]);
   }


   //------ ACCOUNT FOR CAPACITY
   //cout << "ACCOUNT FOR CAPACITY\n";
   for (int i = K+1; i <= N; i++){
        //cout << i << " " << i-K << "\n";
        cw[i] += cw[i-K];
        ccw[i] += ccw[i-K];
    }

    //print
   /*for(int i =0 ; i<cw.size(); i++){
        cout << "cw[" << i << "] = " << cw[i] << "\n";
   }
   cout << "\n";
   for(int i =0 ; i<cw.size(); i++){
        cout << "ccw[" << i << "] = " << ccw[i] << "\n";
   }*/

   //cout << "\n";

   ll no_full = 1e18 + 1;
   ll yes_full = 1e18+1;
   for(int i = 0; i<=N; i++){
        no_full = min(no_full, cw[i] + ccw[N-i]);
        //cout << i << " " << no_full << "\n";
   }
   //cout << "\n";
   for(int i = 0 ; i+K <= N; i++){
         yes_full = min(yes_full, cw[i] + L + ccw[N-(i+K)]);
         //cout << i << " " << yes_full << "\n";
   }

   //cout << no_full << " " << yes_full << "\n";
   //cout << min(no_full, yes_full) << "\n";

   return min(no_full, yes_full);
}

/*
int main(){
    int n;
    int k;
    int l;

    cin >> n >> k >> l;

    int v[n];

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        v[i] = x;
    }

    delivery(n,k,l,v);
}*/