class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, element = -1;

        for(int i=0;i<nums.size();i++){
            if(cnt == 0){
                element = nums[i];
                cnt = 1;
            }
            else if(element == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return element;
    }
};