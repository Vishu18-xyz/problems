class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        unordered_map<char,int> freq;

        for(int i = 0; i<s.size(); i++){
            freq[s[i]]++;
        }
        for(int i = 0; i<order.size(); i++){
            char c = order[i];
            if(freq.find(c) != freq.end()){
                while(freq[c]--){
                  ans+=c;
                }
                freq[c] = 0;
            }
        }

        for(auto it = freq.begin(); it!=freq.end(); it++){
            if(it->second != 0){
               while(it->second --){
                ans+=it->first;
               }
            }
        }

        return ans;
    }
};