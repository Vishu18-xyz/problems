class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;

        for (int i = 0; i < list1.size(); i++) {
            m[list1[i]] = i;
        }

        vector<string> ans;
        int minm = INT_MAX;

        for (int i = 0; i < list2.size(); i++) {
            string s = list2[i];

            if (m.find(s) != m.end()) {
                int sum = i + m[s];

                if (minm > sum) {
                    ans.clear();
                    ans.push_back(s);
                    minm = sum;
                }
                else if (minm == sum) {
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};