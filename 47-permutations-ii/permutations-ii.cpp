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

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        solve(0, nums, result);
        return result;
    }
};
