//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int idx, vector<int>& nums, vector<vector<int>>& result) {
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for (int i = idx; i < nums.size(); ++i) {
            if (seen.find(nums[i]) != seen.end()) continue; // Skip duplicates
            seen.insert(nums[i]);
            swap(nums[idx], nums[i]);
            solve(idx + 1, nums, result);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &nums ,int n) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        solve(0, nums, result);
        sort(result.begin(),result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends