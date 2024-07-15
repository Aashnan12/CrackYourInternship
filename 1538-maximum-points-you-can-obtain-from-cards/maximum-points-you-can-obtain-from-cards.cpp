class Solution {
public:
    int maxScore(vector<int>& A, int k) {
        int n = A.size();
        int sum=0,l=0,r=n-1;

        for(l=0;l<k;l++){
            sum += A[l];
        }

        int maxsum = sum;
        l = l-1;

        while(l >= 0){
            sum = sum + A[r--] - A[l--];
            maxsum = max(maxsum,sum);
        }
        return maxsum;
    }
};