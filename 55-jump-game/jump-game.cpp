class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump = INT_MIN;

        for(int i=0;i<nums.size();i++){
            maxjump = max(maxjump,nums[i]);
            if(i == nums.size()-1) return true;
            if(maxjump == 0) return false;
            maxjump--;
        }
        return true;
    }
};