#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s,x);
    s.push(temp);
}

void rev(stack <int> &s){
    if(s.empty()) return;
    int x=s.top();
    s.pop();
    rev(s); //Recursively call for smaller stack.
    insert(s,x); //Insert the top element at bottom of stack.
}

int main(){
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    rev(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}