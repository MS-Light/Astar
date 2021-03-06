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


int arr[101][101];
priority_queue<pair<int,pair<int, int>>> queue1;
int dist1;

void distance(pair<int,pair<int,int>> pair){
    queue1.pop();
    int a = pair.second.first;
    int b = pair.second.second;
    
    int dist = arr[a][b];
    
    if (a ==100 && b == 100){
        dist1 = dist-2;
        return;
    }
    if ((arr[a][b+1] == 0 ||arr[a][b+1]>dist+1) && b <= 99){
        arr[a][b+1] = dist+1;
        queue1.push(make_pair(a+b-arr[a][b+1],make_pair(a,b+1)));
    }
    if ((arr[a+1][b] == 0 ||arr[a+1][b]>dist+1)&& a <= 99){
        arr[a+1][b] = dist+1;
        queue1.push(make_pair(a+b-arr[a+1][b],make_pair(a+1,b)));
    }
    if ((arr[a][b-1] == 0 ||arr[a][b-1]>dist+1)&& b){
        arr[a][b-1] = dist+1;
        queue1.push(make_pair(a+b-arr[a][b-1],make_pair(a,b-1)));
    }
    if ((arr[a-1][b] == 0 ||arr[a-1][b]>dist+1)&& a){
        arr[a-1][b] = dist+1;
        queue1.push(make_pair(a+b-arr[a-1][b],make_pair(a-1,b)));
    }
    if (!queue1.empty()){
        distance(queue1.top());
    }
}

int main() {
    ifstream infile("/Users/yanbojiang/Projects/ proj/ proj/00.txt");
    for (int i = 0; i< 101; i++){
        for (int j = 0; j<101; j++){
            infile >> arr[i][j];
        }
    }
    infile.close();
    
    queue1.push(make_pair(2,make_pair(0, 0)));
    arr[0][0] = 2;
    
    distance(queue1.top());
    cout<< dist1 <<endl;
    for (int i = 0; i< 101; i++){
        for (int j = 0; j<101; j++){
            cout << arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
