class Solution {
public:
    int minInsertions(string s) {
        string text1 = s;
        string text2 = s;
        int m = text1.size(), n = text2.size();

        reverse(text2.begin(),text2.end());
        //vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        vector<int> prev(n+1,0);


     for(int i = 1; i<=m; i++){
        vector<int> curr(n+1,0);
        for(int j = 1; j<=n; j++){
            if(text1[i-1] == text2[j-1]){
                curr[j] = 1+prev[j-1];
            }
            else{
                curr[j] = max(curr[j-1],prev[j]);
            }
        }
        prev = curr;
    }
    return n-prev[n];
    }
};