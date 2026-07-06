class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mapp1, mapp2;
        string word = "";
        for (auto s : s1) {
            if (s == ' ') {
                if (!word.empty()) {
                    mapp1[word]++;
                    word = "";
                }
            } else {
                word += s;
            }
        }
        if (!word.empty()) mapp1[word]++;
        
        word = "";
        for (char s : s2) {
            if (s == ' ') {
                if (!word.empty()) {
                    mapp2[word]++;
                    word = "";
                }
            } else {
                word += s;
            }
        }
        if (!word.empty()) mapp2[word]++;
        
        vector<string> ans;
        for (auto it : mapp1) {
            if (it.second == 1 && mapp2[it.first] == 0) {
                ans.push_back(it.first);
            }
        }
        
        for (auto it : mapp2) {
            if (it.second == 1 && mapp1[it.first] == 0) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};