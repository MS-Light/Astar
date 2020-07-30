//
//  aStar101.cpp
//   proj
//
//  Created by YANBO JIANG on 6/23/20.
//  Copyright © 2020 YANBO JIANG. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>


using namespace std;

priority_queue<pair<int,pair<int, int> > > queue1;
int arr[1001][1001];
int dist1;

void distance(priority_queue<pair<int,pair<int, int> > > queue1){
    while(!queue1.empty()){
        int a = queue1.top().second.first;
        int b = queue1.top().second.second;
        queue1.pop();
        int dist = arr[a][b];
        
        if (a ==1000 && b == 1000 ){
            dist1 = dist-2;
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

int main(int argc, char* argv[]) {
    ifstream infile("01.txt");
    for (int i = 0; i< 1001; i++){
        for (int j = 0; j<1001; j++){
            infile >> arr[i][j];
        }
    }
    infile.close();
    
    
    queue1.emplace(make_pair(2,make_pair(0, 0)));
    arr[0][0] = 2;
    
    distance(queue1);
    
    
    cout<< dist1 <<endl;
//    for (int i = 0; i< 1001; i++){
//        for (int j = 0; j<1001; j++){
//            cout << arr[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//
    return 0;
}
