//
//  aStar1001.cpp
//   proj
//
//  Created by YANBO JIANG on 6/23/20.
//  Copyright © 2020 YANBO JIANG. All rights reserved.
//
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>


using namespace std;

priority_queue<pair<short int,pair<short int, short int> > > queue1;
short int arr[1001][1001];
short int dist1 = 9999;
stack<pair<short int, pair<short int, short int> > > path;

void distance(priority_queue<pair<short int,pair<short int, short int> > > queue1){
    while(!queue1.empty()){
        short int a = queue1.top().second.first;
        short int b = queue1.top().second.second;
        
        queue1.pop();
        short int dist = arr[a][b];
        
        if (a ==1000 && b == 1000){
            dist1 = dist;
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

int main(int argc, char* argv[]) {
    ifstream infile("02.txt");
    for (short int i = 0; i< 1001; i++){
        for (short int j = 0; j<1001; j++){
            infile >> arr[i][j];
        }
    }
    infile.close();
    
    path.emplace(make_pair(2,make_pair(0, 0)));
    queue1.emplace(make_pair(2,make_pair(0, 0)));
    arr[0][0] = 2;
    
    distance(queue1);
    findTrace(0,0,2);
//    for (short int i = 0; i< 1001; i++){
//        for (short int j = 0; j<1001; j++){
//            cout << arr[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<"The size of path is :"<<path.size()<<endl;
    cout<<"The path is: {";
            while (!path.empty()){
                cout<<"("<<path.top().second.first<<","<<path.top().second.second<<") ";
                path.pop();
            }
    return 0;
}
