//Problem E. Sinking Land
//Contest: AtCoder Beginner Contest 363

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dX;
vector<int> dY;


int main(){
    int h, w, num_years;
    cin >> h >> w >> num_years;
    vector<vector<int> > input(h);
    vector<vector<bool> > inland(h, vector<bool>(w,true) );

    dX.push_back(0);
    dX.push_back(0);
    dX.push_back(-1);
    dX.push_back(1);

    dY.push_back(1);
    dY.push_back(-1);
    dY.push_back(0);
    dY.push_back(0);


    //it's a vector of queues
    //and inside the queue is a PAIR OF COORDINATES
    vector<queue<pair<int,int> > > years(1e5+1);

   // cout << "\n\n";
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            int x;
            cin >> x;
            input[i].push_back(x);
            //cout << x << "   ";

            //check if along perimeter, then add that to the corresponding queue year
            if(((i==0) || (i==h-1)) || ((j==0) || (j==w-1))){
				//
                pair<int, int> coord;
                coord.first = i;
                coord.second = j;
                years[input[i][j]].push(coord);
                //no need to check because it's a guaranteed sink
                inland[i][j] = false;
			}
        }
        //cout << "\n";
    }
    //input is the inputted graph
    //years is the sequences that consist of _sections currently adjacent to the sea that will sink in that year_


    int current_area = h*w;

    for(int i = 1; i<=num_years; i++){
     //   cout << "YEAR " << i << ":\n";

        while(years[i].size() != 0){
           // cout << "Size of YEAR " << i << "     QUEUE: " << years[i].size() << "\n";
            //have a focused point for that year, which is the front of the queue (years[i])
            pair<int, int> focused_point;
            focused_point = years[i].front();
            years[i].pop();

            current_area--;

            //check up

            vector<int> dX;
            dX.clear();
            dX.push_back(0);
            dX.push_back(0);
            dX.push_back(-1);
            dX.push_back(1);

            vector<int> dY;
            dY.clear();
            dY.push_back(1);
            dY.push_back(-1);
            dY.push_back(0);
            dY.push_back(0);

            int n_x = 0; 
            int n_y = 0;

            n_x = focused_point.first;
            n_y = focused_point.second;

            for(int j = 0; j<4; j++){
                int x = 0;
                int y = 0;
                //cout << "QUEUE: " << years[i].size() << "\n";
                if((n_x + dX[j] >= 0) && (n_x + dX[j] < h) && (n_y + dY[j] >= 0) && (n_y + dY[j]  < w)){
                    x = n_x + dX[j];
                    y = n_y + dY[j];
                    if(inland[x][y] == true){
                        pair<int, int> neighbour;

                        neighbour.first = x;
                        neighbour.second = y;

                        if(input[x][y] > i){
                            years[input[x][y]].push(neighbour);
                        }
                        else{
                            years[i].push(neighbour);
                        }
                        inland[x][y] = false;
                    }
                }
                else{
                    //
                }
            }
           // cout << current_area << "\n";
        }

    cout << current_area << "\n";


    /*
    for(int i=0; i<h; i++){
        for(int j = 0; j<w; j++){
            
        }
    }*/
    }
}