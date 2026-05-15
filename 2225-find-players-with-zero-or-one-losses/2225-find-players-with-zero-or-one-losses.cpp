class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        set<int> st;                  
        int n = matches.size();

        for(int i = 0; i<n; i++){
            int winner = matches[i][0];
            int loser =  matches[i][1];

            st.insert(winner);
            st.insert(loser);

            mp[loser]++;
        }
        vector<int> lose0;
        vector<int> lose1;

        for (int player : st) {
        if (mp[player] == 0) {
            lose0.push_back(player);
        }
        else if (mp[player] == 1) {
            lose1.push_back(player);
        }
       }
        ans.push_back(lose0);
        ans.push_back(lose1);

        return ans;
    }
};