class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0, j = 1;
        set<pair<int,int>> st;
        while(j < n && i < n){
            int diff = abs(nums[i] - nums[j]);
            if(diff == k && i != j){
                st.insert({nums[i],nums[j]});
                i++;
                j++;
            }
            else if(diff < k){
                j++;
            }
            else{
                i++;
            }
        }
        return st.size();
    }
};