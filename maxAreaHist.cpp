#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector <long long> left,right;
        stack <pair<long long,long long>> s;
        //Left to store NSL idx;
        //Right to store NSR idx;
        for(int i=0;i<n;i++){
            while(!s.empty() and s.top().first>=arr[i]){
                s.pop();
            }
            s.empty()? left.push_back(-1):left.push_back(s.top().second);
            s.push({arr[i],i});
        }
        while(!s.empty()) s.pop(); //To clear  the stack.
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and s.top().first>=arr[i]){
                s.pop();
            }
            s.empty()? right.push_back(n):right.push_back(s.top().second);
            s.push({arr[i],i});
        }
        reverse(right.begin(),right.end());
        vector <long long> width(n,0);
        for(int i=0;i<n;i++){
            width[i]=right[i]-left[i]-1;
        }
        vector <long long> area(n,0);
        for(int i=0;i<n;i++){
            area[i]=arr[i]*width[i];
        }
        return *max_element(area.begin(),area.end());
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends