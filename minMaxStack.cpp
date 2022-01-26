#include <bits/stdc++.h>
using namespace std;

class minMaxStack{
    vector <int> stack;
    vector <int> minStack;
    vector <int> maxStack;
    public:
    void push(int data){
        int currMin=data;
        int currMax=data;
        if(minStack.size()) currMin=min(minStack[minStack.size()-1],data);
        if(maxStack.size()) currMax=max(maxStack[maxStack.size()-1],data);
        minStack.push_back(currMin);
        maxStack.push_back(currMax);
        stack.push_back(data);
    }
    int getMin(){
        return minStack[minStack.size()-1];
    }
    int getMax(){
        return maxStack[maxStack.size()-1];
    }
    int top(){
        return stack[stack.size()-1];
    }
    bool empty(){
        return stack.size()==0;
    }
    void pop(){
        minStack.pop_back();
        maxStack.pop_back();
        stack.pop_back();
    }
};

int main(){
    minMaxStack s;
    s.push(1);
    s.push(5);
    s.push(3);
    s.push(8);
    cout<<s.getMax()<<endl;
    s.pop();
    cout<<s.getMax()<<endl;
    cout<<s.getMin()<<endl;
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}