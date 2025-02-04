class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int prod = 1;
        for(int i=0;i<n;i++){
            result[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for(int i=n-1;i>=0;i--){
            result[i] *= prod;
            prod *= nums[i];
        }
        return result;
    }
};