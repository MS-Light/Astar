
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>


using namespace std;

priority_queue<pair<int,pair<short int, short int> > > queue1;

int arr[1001][1001];
int dist1 = 999999;
//char arr2[1001][1001];
short int start_a = 0;
short int start_b = 0;
bool checker = false;


void distance(priority_queue<pair<int,pair<short int, short int> > > queue1){
    while(!queue1.empty()){
        short int a = queue1.top().second.first;
        short int b = queue1.top().second.second;
        
        queue1.pop();
        int dist = arr[a][b];
        
        if (a ==1000 && b == 1000){
            dist1 = dist;
            checker = true;
            break;
        }
        if ((arr[a][b+1] == 0 ||arr[a][b+1]>dist+1) && b < 1000){
            arr[a][b+1] = dist+1;
            queue1.emplace(make_pair(a+b-arr[a][b+1],make_pair(a,b+1)));
        }
        if ((arr[a+1][b] == 0 ||arr[a+1][b]>dist+1) && a < 1000){
            arr[a+1][b] = dist+1;
            queue1.emplace(make_pair(a+b-arr[a+1][b],make_pair(a+1,b)));
        }
        if ((arr[a][b-1] == 0 ||arr[a][b-1]>dist+1)&& b){
            arr[a][b-1] = dist+1;
            queue1.emplace(make_pair(a+b-arr[a][b-1],make_pair(a,b-1)));
        }
        if ((arr[a-1][b] == 0 ||arr[a-1][b]>dist+1)&& a){
            arr[a-1][b] = dist+1;
            queue1.emplace(make_pair(a+b-arr[a-1][b],make_pair(a-1,b)));
        }
    }
}

void showPath(stack<pair<int,pair<short int, short int> > > path){
    cout<<"The path is: {";
            while (!path.empty()){
                int a = path.top().second.first;
                int b = path.top().second.second;
                cout<<"("<<a<<","<<b<<") ";
//                arr2[a][b] = 46;
                path.pop();
            }
    cout<<endl;
//    for (short int i = 0; i< 1001; i++){
//        for (short int j = 0; j<1001; j++){
//            cout << arr2[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}

int findTrace(short int a,short int b, int dist){
    stack<pair<int, pair<short int,short int> > > path;
    path.emplace(make_pair(2,make_pair(start_a, start_b)));
    while (dist!=dist1){
        a = path.top().second.first;
        b = path.top().second.second;
        if (arr[a][b+1] == dist+1){
            b+=1;
            path.emplace(make_pair(dist, make_pair(a, b)));
            dist+=1;
        }
        else if (arr[a+1][b] == dist+1){
            a+=1;
            path.emplace(make_pair(dist, make_pair(a, b)));
            dist+=1;
        }
        else if (arr[a-1][b] == dist+1){
            a-=1;
            path.emplace(make_pair(dist, make_pair(a, b)));
            dist+=1;
        }
        else if (arr[a][b-1] == dist+1){
            b-=1;
            path.emplace(make_pair(dist, make_pair(a, b)));
            dist+=1;
        }
        else{
            path.pop();
            arr[a][b] = 0;
            dist-=1;
        }
    }
    showPath(path);
    return int(path.size()-1);
}

void run(){
    queue1.emplace(make_pair(2,make_pair(0, 0)));
    arr[0][0] = 2;
    
    distance(queue1);
    if (checker == false){
        cout<<"No Path!"<<endl;
        return;
    }
    checker = false;
    cout<<"The size of path is :"<<findTrace(0,0,2)<<endl;

}

int main(int argc, char* argv[]) {
    auto start = std::chrono::high_resolution_clock::now();
    ifstream infile("backTrackerMazes1000/10.txt");
    for (short int i = 0; i< 1001; i++){
        for (short int j = 0; j<1001; j++){
            infile >> arr[i][j];
//            arr2[i][j] = arr[i][j];
        }
    }
    infile.close();
    
    run();
    chrono::high_resolution_clock::time_point stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = duration_cast<chrono::microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << endl;
    return 0;
}
