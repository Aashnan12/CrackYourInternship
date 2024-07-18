class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq; // yi-xi,xi

        int ans = INT_MIN;

        for(int i=0;i<points.size();i++){
            int xi = points[i][0];
            int yi = points[i][1];

            while(!pq.empty() && (xi - pq.top().second) > k ){
                pq.pop();
            }

            if(!pq.empty()){
                ans = max(ans,yi + xi + pq.top().first);
            }

            pq.push({yi - xi, xi});

        }
        return ans;
    }
};