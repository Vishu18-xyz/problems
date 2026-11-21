class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
         int n = rain.size();

        int alice = 0;
        int bob = 0;

        vector<string> ans(n, "None");

        for (int i = 0; i < n; i++) {
            bool aliceNeeds = (i < n - 1 && rain[i] == 1 && rain[i + 1] == 1);
            bool bobNeeds = (rain[i] == 1);

            if (aliceNeeds && bobNeeds) {
                if (alice <= bob) {
                    ans[i] = "Alice";
                    alice++;
                } else {
                    ans[i] = "Bob";
                    bob++;
                }
            }
            else if (aliceNeeds) {
                ans[i] = "Alice";
                alice++;
            }
            else if (bobNeeds) {
                ans[i] = "Bob";
                bob++;
            }
        }

        return ans;
    }
};