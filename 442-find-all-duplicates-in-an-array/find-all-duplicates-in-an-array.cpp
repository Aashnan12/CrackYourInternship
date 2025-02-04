class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            int idx = abs(nums[i]);
            if(nums[idx-1] < 0){
                ans.push_back(idx);
            }
            else{
                nums[idx-1] *= -1;
            }
        }
        return ans;
    }
};