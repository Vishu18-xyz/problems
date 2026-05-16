class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string w = "";

        for(int i = 0; i<s.size(); i++){
            if(s[i]!=' '){
                w = w+s[i];
            }
            else{
                words.push_back(w);
                w = "";
                continue;
            }
        }

        words.push_back(w);

        int n = pattern.size();

        if(n!=words.size()){
            return false;
        }

        unordered_map<string,char> mp;
        set<char> used;

        for(int i = 0; i<n; i++){
            string word = words[i];
            char ch = pattern[i];

            if(mp.find(word) == mp.end() && used.find(ch) == used.end()){
                used.insert(ch);
                mp[word] = ch;
            }
            else if(mp[word] != pattern[i]){
                return false;
            }
        }

        return true;
         
    }
};