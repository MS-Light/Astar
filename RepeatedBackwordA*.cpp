
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

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
    //showPath(path);
    return int(path.size()-1);
}


//int findTrace(int a, int b, int dist,stack<pair<short int,pair<short int, short int> > > path){
//    while (dist!=dist1){
//        a = path.top().second.first;
//        b = path.top().second.second;
//        if (arr[a][b+1] == dist+1){
//            b+=1;
//            path.emplace(make_pair(dist, make_pair(a, b)));
//            dist+=1;
//        }
//        else if (arr[a+1][b] == dist+1){
//            a+=1;
//            path.emplace(make_pair(dist, make_pair(a, b)));
//            dist+=1;
//        }
//        else if (arr[a-1][b] == dist+1){
//            a-=1;
//            path.emplace(make_pair(dist, make_pair(a, b)));
//            dist+=1;
//        }
//        else if (arr[a][b-1] == dist+1){
//            b-=1;
//            path.emplace(make_pair(dist, make_pair(a, b)));
//            dist+=1;
//        }
//        else{
//            path.pop();
//            arr[a][b] = 0;
//            dist-=1;
//        }
//    }
//    return int(path.size()-1);
//}


bool distance2(priority_queue<pair<pair<short int,short int>, pair<short int, short int> > > queue2){
    short int endpointa = queue2.top().second.first;
    short int endpointb = queue2.top().second.second;
    queue2.pop();
    queue2.emplace(make_pair(make_pair(2,0),make_pair(100, 100)));
    
    while(!queue2.empty()){
        short int a = queue2.top().second.first;
        short int b = queue2.top().second.second;
        queue2.pop();
        short int dist = graph[a][b];
        if (a ==endpointa && b == endpointb){
            dist2 = dist;
            return true;
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
    return false;
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
            if (!distance2(queue2)){
                h[a][b] = -999;
            };
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

//    cout<<"The path is: {";
//            while (!path.empty()){
//                cout<<"("<<path.top().second.first<<","<<path.top().second.second<<") ";
//                path.pop();
//            }
//    cout<<endl;
//
//    for (short int i = 0; i< 101; i++){
//        for (short int j = 0; j<101; j++){
//            cout << arr[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<findTrace(0,0,2, dist1, arr)<<endl;
}

int main(int argc, char* argv[]) {
    auto start = chrono::high_resolution_clock::now();
    for (int n = 0; n<50; n++){
        string filename = "randGrid/";
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
