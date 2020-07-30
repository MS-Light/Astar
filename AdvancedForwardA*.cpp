//
//  RepeatedForwardA*.cpp
//   proj
//
//  Created by YANBO JIANG on 7/7/20.
//  Copyright © 2020 YANBO JIANG. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

priority_queue<pair<short int,pair<short int, short int> > > queue1;
stack<pair<short int,pair<short int, short int> > > path;

int arr[101][101];
int graph[101][101];
short int h[101][101];
short int dist1 = 9999;
short int dist2 = 9999;
short int path_val = 0;


void findTrace(int a, int b, int dist){
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
}

// void findTrace(int a, int b, int dist,short int dst, int graph[][101]){
//    stack<pair<short int,pair<short int, short int> > > path;
//    path.push(make_pair(2,make_pair(0, 0)));
//    while (dist!=dst){
//        a = path.top().second.first;
//        b = path.top().second.second;
//        if (graph[a][b+1] == dist+1){
//            b+=1;
//            path.push(make_pair(dist, make_pair(a, b)));
//            dist+=1;
//        }
//        else if (graph[a+1][b] == dist+1){
//            a+=1;
//            path.push(make_pair(dist, make_pair(a, b)));
//            dist+=1;
//        }
//        else if (graph[a-1][b] == dist+1){
//            a-=1;
//            path.push(make_pair(dist, make_pair(a, b)));
//            dist+=1;
//        }
//        else if (graph[a][b-1] == dist+1){
//            b-=1;
//            path.push(make_pair(dist, make_pair(a, b)));
//            dist+=1;
//        }
//        else{
//            path.pop();
//            graph[a][b] = 0;
//            dist-=1;
//        }
//    }
//    path_val = int(path.size());
//    return;
//}

int distance2(priority_queue<pair<short int,pair<short int, short int> > > queue2){
    
    while(!queue2.empty()){
        short int a = queue2.top().second.first;
        short int b = queue2.top().second.second;
        queue2.pop();
        short int dist = graph[a][b];
        if (a ==100 && b == 100){
            dist2 = dist;
            return 201-dist;
        }
        if ((graph[a][b+1] == 0 ||graph[a][b+1]>dist+1) && b < 100){
            graph[a][b+1] = dist+1;
            queue2.emplace(make_pair(h[a][b+1]-graph[a][b+1],make_pair(a,b+1)));
        }
        if ((graph[a+1][b] == 0 ||graph[a+1][b]>dist+1) && a < 100){
            graph[a+1][b] = dist+1;
            queue2.emplace(make_pair(h[a+1][b]-graph[a+1][b],make_pair(a+1,b)));
        }
        if ((graph[a][b-1] == 0 ||graph[a][b-1]>dist+1)&& b){
            graph[a][b-1] = dist+1;
            queue2.emplace(make_pair(h[a][b-1]-graph[a][b-1],make_pair(a,b-1)));
        }
        if ((graph[a-1][b] == 0 ||graph[a-1][b]>dist+1)&& a){
            graph[a-1][b] = dist+1;
            queue2.emplace(make_pair(h[a-1][b]-graph[a-1][b],make_pair(a-1,b)));
        }
    }
    return -999;
}


void distance(priority_queue<pair<short int,pair<short int, short int> > > queue1){
    while(!queue1.empty()){
        priority_queue<pair<short int,pair<short int, short int> > > queue2;
        short int a = queue1.top().second.first;
        short int b = queue1.top().second.second;
        bool check = 0;
        queue1.pop();
        short int dist = arr[a][b];
        if (a ==100 && b == 100){
            dist1 = dist;
            break;
        }
        
        if ((arr[a][b+1] == 0 ||arr[a][b+1]>dist+1) && b < 100){
            arr[a][b+1] = dist+1;
            queue1.emplace(make_pair(h[a][b+1]-arr[a][b+1],make_pair(a,b+1)));
        }else if (graph[a][b+1] != 1 && arr[a+1][b] == 1) {
            check = 1;
            graph[a][b+1] =arr[a][b+1];
        }
        if ((arr[a+1][b] == 0 ||arr[a+1][b]>dist+1) && a < 100){
            arr[a+1][b] = dist+1;
            queue1.emplace(make_pair(h[a+1][b]-arr[a+1][b],make_pair(a+1,b)));
        }else if (graph[a+1][b] != 1 && arr[a+1][b] == 1){
            check = 1;
            graph[a+1][b] = arr[a+1][b];
        }
        if ((arr[a][b-1] == 0 ||arr[a][b-1]>dist+1)&& b){
            arr[a][b-1] = dist+1;
            queue1.emplace(make_pair(h[a][b-1]-arr[a][b-1],make_pair(a,b-1)));
        }else if (graph[a][b-1] != 1 && arr[a+1][b] == 1){
            check = 1;
            graph[a][b-1] = arr[a][b-1];
        }
        if ((arr[a-1][b] == 0 ||arr[a-1][b]>dist+1)&& a){
            arr[a-1][b] = dist+1;
            queue1.emplace(make_pair(h[a-1][b]-arr[a-1][b],make_pair(a-1,b)));
        }else if (graph[a-1][b] != 1 && arr[a+1][b] == 1){
            check = 1;
            graph[a][b] = arr[a-1][b];
        }
        if (check == true){
            queue2.emplace(make_pair(2,make_pair(a, b)));
            h[a][b] = distance2(queue2);
        }
        if (graph[a][b] == -1){
            cout<<"NO Path!"<<endl;
            exit(0);
        }
        
    }
    if (queue1.empty()){
        cout<<"NO PATH!!"<<endl;
        exit(0);
    }
    return;
    
}



int main(int argc, char* argv[]) {
    ifstream infile("00.txt");
    for (short int i = 0; i< 101; i++){
        for (short int j = 0; j<101; j++){
            infile >> arr[i][j];
            h[i][j] = i+j;
            graph[i][j] = 0;
        }
    }
    infile.close();
    

    
    short int a = 0;
    short int b = 0;
    arr[a][b] = 2;
    queue1.emplace(make_pair(2,make_pair(a, b)));
    path.emplace(make_pair(2,make_pair(0, 0)));
    distance(queue1);
    
    findTrace(0,0,2);
    
    cout<<"The size of path is :"<<path.size()-1<<endl;
    cout<<"The path is: {";
            while (!path.empty()){
                cout<<"("<<path.top().second.first<<","<<path.top().second.second<<") ";
                path.pop();
            }
    cout<<endl;

    for (short int i = 0; i< 101; i++){
        for (short int j = 0; j<101; j++){
            cout << arr[i][j]<<" ";
        }
        cout<<endl;
    }
//    cout<<findTrace(0,0,2, dist1, arr)<<endl;
    return 0;
}

