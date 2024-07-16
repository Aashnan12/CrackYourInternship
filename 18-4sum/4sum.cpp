class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long newtarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1;
                int high = n-1;

                while(low < high){
                    if(nums[low] + nums[high] < newtarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newtarget){
                        high--;
                    }
                    else{
                        result.push_back({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;
                        while(low < high && nums[low-1]==nums[low]) low++;
                        while(high > low && nums[high+1]==nums[high]) high--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};