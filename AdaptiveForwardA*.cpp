
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

priority_queue<pair<pair<short int,short int>, pair<short int, short int> > > queue1;


int arr[101][101];
int graph[101][101];
short int h[101][101];
short int dist1 = 9999;
short int dist2 = 9999;
short int path_val = 0;
bool pathchecker = false;
char arr2[101][101];


void showPath(stack<pair<short int,pair<short int, short int> > > path){
    cout<<"The path is: {";
            while (!path.empty()){
                short int a = path.top().second.first;
                short int b = path.top().second.second;
                cout<<"("<<a<<","<<b<<") ";
                arr2[a][b] = 46;
                path.pop();
            }
    cout<<endl;
    for (short int i = 0; i< 101; i++){
        for (short int j = 0; j<101; j++){
            cout << arr2[i][j]<<" ";
        }
        cout<<endl;
    }
}

int findTrace(int a, int b, int dist){
    stack<pair<short int, pair<short int, short int> > > path;
    path.emplace(make_pair(2,make_pair(0, 0)));
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
//    showPath(path);
    return int(path.size()-1);
}

int distance2(priority_queue<pair<pair<short int,short int>, pair<short int, short int> > > queue2){
    
    while(!queue2.empty()){
        short int a = queue2.top().second.first;
        short int b = queue2.top().second.second;
        short int dist = queue2.top().first.second;
        queue2.pop();
        if (a ==100 && b == 100){
            dist2 = dist;
            return dist;
        }
        if ((graph[a][b+1] == 0 ||graph[a][b+1]>dist+1) && b < 100){
            graph[a][b+1] = dist+1;
            queue2.emplace(make_pair(make_pair(-h[a][b+1]-graph[a][b+1],graph[a][b+1]),make_pair(a,b+1)));;
        }
        if ((graph[a+1][b] == 0 ||graph[a+1][b]>dist+1) && a < 100){
            graph[a+1][b] = dist+1;
            queue2.emplace(make_pair(make_pair(-h[a+1][b]-graph[a+1][b],graph[a+1][b]),make_pair(a+1,b)));
        }
        if ((graph[a][b-1] == 0 ||graph[a][b-1]>dist+1)&& b){
            graph[a][b-1] = dist+1;
            queue2.emplace(make_pair(make_pair(-h[a][b-1]-graph[a][b-1],graph[a][b-1]),make_pair(a,b-1)));
        }
        if ((graph[a-1][b] == 0 ||graph[a-1][b]>dist+1)&& a){
            graph[a-1][b] = dist+1;
            queue2.emplace(make_pair(make_pair(-h[a-1][b]-graph[a-1][b],graph[a-1][b]),make_pair(a-1,b)));
        }
    }
    return -999;
}


void distance(priority_queue<pair<pair<short int,short int>, pair<short int, short int> > > queue1){
    while(!queue1.empty()){
        priority_queue<pair<pair<short int,short int>, pair<short int, short int> > > queue2;
        short int a = queue1.top().second.first;
        short int b = queue1.top().second.second;
        bool check = 0;
        queue1.pop();
        short int dist = arr[a][b];
        if (a ==100 && b == 100){
            dist1 = dist;
            pathchecker = true;
            break;
        }
        
        if ((arr[a][b+1] == 0 ||arr[a][b+1]>dist+1) && b < 100){
            arr[a][b+1] = dist+1;
            queue1.emplace(make_pair(make_pair(-h[a][b+1]-arr[a][b+1],arr[a][b+1]),make_pair(a,b+1)));
        }else if (graph[a][b+1] != 1 && arr[a+1][b] == 1) {
            check = 1;
            graph[a][b+1] =arr[a][b+1];
        }
        if ((arr[a+1][b] == 0 ||arr[a+1][b]>dist+1) && a < 100){
            arr[a+1][b] = dist+1;
            queue1.emplace(make_pair(make_pair(-h[a+1][b]-arr[a+1][b],arr[a+1][b]),make_pair(a+1,b)));
        }else if (graph[a+1][b] != 1 && arr[a+1][b] == 1){
            check = 1;
            graph[a+1][b] = arr[a+1][b];
        }
        if ((arr[a][b-1] == 0 ||arr[a][b-1]>dist+1)&& b){
            arr[a][b-1] = dist+1;
            queue1.emplace(make_pair(make_pair(-h[a][b-1]-arr[a][b-1],arr[a][b-1]),make_pair(a,b-1)));
        }else if (graph[a][b-1] != 1 && arr[a+1][b] == 1){
            check = 1;
            graph[a][b-1] = arr[a][b-1];
        }
        if ((arr[a-1][b] == 0 ||arr[a-1][b]>dist+1)&& a){
            arr[a-1][b] = dist+1;
            queue1.emplace(make_pair(make_pair(-h[a-1][b]-arr[a-1][b],arr[a-1][b]),make_pair(a-1,b)));
        }else if (graph[a-1][b] != 1 && arr[a+1][b] == 1){
            check = 1;
            graph[a][b] = arr[a-1][b];
        }
        if (check == true){
            queue2.emplace(make_pair(make_pair(dist,0),make_pair(a, b)));
            h[a][b] = distance2(queue2);
        }
        if (graph[a][b] == -1){
            cout<<"NO Path!"<<endl;
            return;
        }
        
    }
    return;
    
}

void run (){
    short int a = 0;
    short int b = 0;
    arr[a][b] = 2;
    queue1.emplace(make_pair(make_pair(2,0),make_pair(a, b)));
    
    distance(queue1);
    
    if (pathchecker == false){
        cout<<"No Path!"<<endl;
        return;
    }
    pathchecker = false;
    int pathlength = findTrace(0,0,2);
    cout<<"The size of path is :"<<pathlength<<endl;
}

int main(int argc, char* argv[]) {
    auto start = chrono::high_resolution_clock::now();
    for (int n = 50; n<100; n++){
        string filename = "backTrackerMazes/";
        if (n<10) filename += "0";
        filename += to_string(n)+".txt";


        ifstream infile(filename);
        for (short int i = 0; i< 101; i++){
            for (short int j = 0; j<101; j++){
                infile >> arr[i][j];
                arr2[i][j] = arr[i][j]+48;
                h[i][j] = 200-i-j;
                graph[i][j] = 0;
            }
        }
        infile.close();
        run();
    }

        
//        ifstream infile("randGrid/02.txt");
//        for (short int i = 0; i< 101; i++){
//            for (short int j = 0; j<101; j++){
//                infile >> arr[i][j];
//                h[i][j] = i+j;
//                graph[i][j] = 0;
//            }
//        }
//        infile.close();
//
//
//        run();
        

    
    
//    cout<<findTrace(0,0,2, dist1, arr)<<endl;
    chrono::high_resolution_clock::time_point stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = duration_cast<chrono::microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << endl;
    return 0;
}

