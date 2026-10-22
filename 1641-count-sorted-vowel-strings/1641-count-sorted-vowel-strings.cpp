class Solution {
public:
    int count(int i, int n, string &vowels,vector<vector<int>> &dp){

   		if(n==0) return 1;

   		if(i>=5) return 0; 

   		return count(i+1, n, vowels,dp)+count(i, n-1, vowels,dp);;
   }

    int countVowelStrings(int n) {
        string vowels= "aeiou";
        vector<vector<int>> dp(5, vector<int>(n+1, -1));
   	    return count(0, n, vowels,dp);
    }
};