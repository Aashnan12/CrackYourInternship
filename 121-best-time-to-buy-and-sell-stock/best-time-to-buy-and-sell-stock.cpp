class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxprofit = 0;

        for(int it : prices){
            mini = min(mini,it);
            maxprofit = max(maxprofit,it - mini);
        }
        return maxprofit;
    }
};