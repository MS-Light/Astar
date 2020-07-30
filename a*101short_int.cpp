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
#include <string>


using namespace std;


priority_queue<pair<short int,pair<short int, short int> > > queue1;
int arr[101][101];
short int dist1 = 9999;
string filetitle;

void findTrace(int a, int b, int dist, stack<pair<short int, pair<short int, short int> > > path){
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
    cout<<"The size of path is :"<<path.size()<<endl;
//    cout<<"The path is: {";
//            while (!path.empty()){
//                cout<<"("<<path.top().second.first<<","<<path.top().second.second<<") ";
//                path.pop();
//            }
//    cout<<endl;

}

void distance(priority_queue<pair<short int,pair<short int, short int> > > queue1){
    while(!queue1.empty()){
        short int a = queue1.top().second.first;
        short int b = queue1.top().second.second;
        
        queue1.pop();
        short int dist = arr[a][b];
        
        if (a ==100 && b == 100){
            dist1 = dist;
            stack<pair<short int, pair<short int, short int> > > path;
            path.emplace(make_pair(2,make_pair(0, 0)));
            findTrace(0,0,2,path);
            return;
        }
        if ((arr[a][b+1] == 0 ||arr[a][b+1]>dist+1) && b < 100){
            arr[a][b+1] = dist+1;
            queue1.emplace(make_pair(a+b-arr[a][b+1],make_pair(a,b+1)));
        }
        if ((arr[a+1][b] == 0 ||arr[a+1][b]>dist+1) && a < 100){
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
    cout<<filetitle<<" do not have any path!"<<endl;
    return;
}


void run(){
    queue1.emplace(make_pair(2,make_pair(0, 0)));
    arr[0][0] = 2;
    
    distance(queue1);
    
//    for (short int i = 0; i< 101; i++){
//        for (short int j = 0; j<101; j++){
//            cout << arr[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}

int main(int argc, char* argv[]) {
    for (int n = 0; n<10; n++){
        string filename = "randGrid/";
        if (n<10) filename += "0";
        filename += to_string(n)+".txt";

        filetitle = filename;
        ifstream infile(filename);
        for (short int i = 0; i< 101; i++){
            for (short int j = 0; j<101; j++){
                infile >> arr[i][j];
            }
        }
        infile.close();
        run();
   }
    
    return 0;
}
