
//Stack definition using dynamic array aka vectors

#include <iostream>
#include <vector>
using namespace std;

struct MyStack {
    vector <int> v;
    void push(int x) {
        v.push_back(x);
    }
    int pop() {
        int res = v.back();
        v.pop_back();
        return res;
    }
    int peek() {
        return v.back();
    }
    bool empty() {
        return v.empty();
    }
};