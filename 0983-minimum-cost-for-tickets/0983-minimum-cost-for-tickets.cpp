class Solution {
public:
    int solve(vector<int>&days, vector<int>&costs,int index, vector<int> &dp){

        if(index >= days.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int one = costs[0]+solve(days,costs,index+1,dp);

        int i = index;
        while(i<days.size() && days[i] < days[index]+7){
            i++;
        }
        int seven = costs[1]+solve(days,costs,i,dp);
         i = index;
        while (i < days.size() && days[i] < days[index] + 30) {
            i++;
        }
        int thirty = costs[2] + solve(days, costs, i,dp);

        return dp[index] = min(one, min(seven, thirty));

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n,-1);
       return solve(days,costs,0,dp);
    }
};