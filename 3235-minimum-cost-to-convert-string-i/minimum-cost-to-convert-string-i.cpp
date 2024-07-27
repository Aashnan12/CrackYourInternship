class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        int n = source.size();
        vector<vector<long long >> Floyd(26,vector<long long>(26,INT_MAX));

        for(int i=0;i<26;i++){
            Floyd[i][i] = 0;
        }

        for(int i=0;i<original.size();i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            Floyd[u][v] = min(Floyd[u][v] , (long long)cost[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    Floyd[i][j] = min(Floyd[i][j],Floyd[i][k] + Floyd[k][j]);
                }
            }
        }
        long long ans = 0;

        for(int i=0;i<n;i++){
            if(Floyd[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1;
            ans += Floyd[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
};