class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = knowledge.size();
        unordered_map<string,string> mp;

        for(int i = 0; i<n; i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        int size = s.size();
        string ans = "";
        int i = 0;
        while(i<size){
            if(s[i] == '('){
                string inner = "";
                i++;
                while(s[i] != ')'){
                    inner += s[i];
                    i++;
                }

                if(mp.find(inner) != mp.end()){
                    ans += mp[inner];
                }
                else{
                    ans += '?';
                }
                i++;
            }
            else{
                ans+=s[i];
                i++;
            }
        }

        return ans;

    }
};