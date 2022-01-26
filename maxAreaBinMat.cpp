#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
   int getMaxArea(vector <int> &arr, int n)
    {
        // Your code here
        vector <int> left,right;
        stack <pair<int,int>> s;
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
        vector <int> width(n,0);
        for(int i=0;i<n;i++){
            width[i]=right[i]-left[i]-1;
        }
        vector <int> area(n,0);
        for(int i=0;i<n;i++){
            area[i]=arr[i]*width[i];
        }
        return *max_element(area.begin(),area.end());
    }
    int maxArea(int arr[MAX][MAX], int n, int m) {
        // Your code here
        vector <int> v;
        for(int j=0;j<m;j++){
            v.push_back(arr[0][j]);
        }
        int sz=v.size();
        int mx=getMaxArea(v,sz);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0) v[j]=0;
                else v[j]+=arr[i][j];
            }
            sz=v.size();
            mx=max(mx,getMaxArea(v,sz));
        }
        return mx;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends