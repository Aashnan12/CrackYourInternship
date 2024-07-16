class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int elements = m*n;

        int sr = 0;
        int sc = 0;
        int er = m-1;
        int ec = n-1;
        int count = 0;

        vector<int> result;

        while(count < elements){
            
            for(int i = sc;count < elements  && i<=ec;i++){
                result.push_back(matrix[sr][i]);
                count++;
            }
            sr++;

            for(int i = sr;count < elements  && i<=er;i++){
                result.push_back(matrix[i][ec]);
                count++;
            }
            ec--;

            for(int i = ec;count < elements  && i >= sc;i--){
                result.push_back(matrix[er][i]);
                count++;
            }
            er--;

            for(int i = er;count < elements  && i >= sr;i--){
                result.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
        }

        return result;
    }
};