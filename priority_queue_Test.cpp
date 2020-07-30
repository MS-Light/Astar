//
//  priority_queue_Test.cpp
//   proj
//
//  Created by YANBO JIANG on 7/10/20.
//  Copyright © 2020 YANBO JIANG. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
  
// Function to print the data of
// the priority queue ordered by first
void showpq(
    priority_queue<pair<int, int> > g)
{
    // Loop to print the elements
    // until the priority queue
    // is not empty
    while (!g.empty()) {
        cout << g.top().first
             << " " << g.top().second
             << endl;
        g.pop();
    }
    cout << endl;
}
  
// Driver Code
int main()
{
    priority_queue<pair<int, int> > p1;
  
    // Insertion of elements
    p1.push(make_pair(9, 5));
    p1.push(make_pair(9, 4));
    p1.push(make_pair(9, 6));
    p1.push(make_pair(9, 3));
    p1.push(make_pair(9, 4));
    showpq(p1);
    return 0;
}
