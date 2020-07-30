//
//  practice.cpp
//   proj
//
//  Created by YANBO JIANG on 7/9/20.
//  Copyright © 2020 YANBO JIANG. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int jump(vector<int>& nums) {
//    vector<int> temp(nums.size(), 99999);
//    temp[0] = 0;
//    for (int i = 1; i<nums.size(); i++){
//        for (int j = i-1; j>=0; j--){
//            if (j+nums[j] >= i && temp[i] > temp[j]+1){
//                temp[i] = temp[j]+1;
//            }
//        }
//        cout<<temp[i]<<" "<<endl;
//    }
// return temp[nums.size()-1];
//}


int main(){
    vector<int> nmsl ={2,3,1,1,4};
    cout<<*max_element(nmsl.begin()+1, nmsl.begin()+2)<<endl;
 
    return 0;
}
