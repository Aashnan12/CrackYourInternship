class Solution {
public:
    int strStr(string A, string B) {
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                if(A[i+j] != B[j]){
                    break;
                }
                if(j == B.size()-1){
                    return i;
                }
            }
        }
        return -1;
    }
};