class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i = 0;
        for(  ;i < heights.size()-1; i++){
            if(heights[i+1] <= heights[i]) continue;
            
            int diff = heights[i+1] - heights[i];
            if(diff <= bricks){
                bricks -= diff;
                pq.push(diff);
            }
            else if(ladders > 0){
                if(!pq.empty()){
                    int max_brick_used = pq.top();

                    if(diff < max_brick_used){
                        bricks += max_brick_used;
                        pq.pop();
                        bricks -= diff;
                        pq.push(diff);
                    }
                }
                ladders--;
            }
            else{
                break;
            }
        }
        return i;
    }
};

// Memory Limit Exceeded
// class Solution {
// public:
//     vector<vector<int>> t;
//     int solve(vector<int>& heights,int idx,int b,int l){
//         if(idx == heights.size()-1){
//             return 0;
//         }
//         if(t[b][l] != -1) {
//             return t[b][l];
//         }
//         if(heights[idx+1] <= heights[idx]){
//             return t[b][l] = 1 + solve(heights,idx+1,b,l);
//         }
//         else{
//             int using_bricks = 0;
//             int using_ladders = 0;
//             int diff = heights[idx+1] - heights[idx];
//             if(diff <= b){
//                 using_bricks = 1 + solve(heights,idx+1,b - diff,l);
//             }
//             if(l > 0){
//                 using_ladders = 1 + solve(heights,idx+1,b,l-1);
//             }
//             return t[b][l] = max(using_bricks,using_ladders);
//         }
//         return -1;
//     }
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         t = vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1));
//         return solve(heights,0,bricks,ladders);
//     }
// };