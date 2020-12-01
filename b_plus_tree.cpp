//
//  main.cpp
//  btree
//
//  Created by Wongi, Baek on 12/1/20.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Node {
    int N;
    vector<string> values;
    vector<Node> ptrs;
};

struct btree {
    int N;
    Node * root;
    btree(int n) {
        root = new Node();
        root->N = n;
        root->values.resize(3);
        root->ptrs.resize(4);
    }
    
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
