#include <bits/stdc++.h>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);

stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends


void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return s.size() == n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.size() == 0;
}

int pop(stack<int>& s){
	// Your code goes here
	if(!isEmpty(s))
	{
	    s.pop();
	}
}

int getMin(stack<int>& s){
	// Your code goes here
	int minv = s.top();
	while(!isEmpty(s))
	{
	    minv = min(minv, s.top());
	    s.pop();
	}
	return minv;
}