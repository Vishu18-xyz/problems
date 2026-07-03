class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string word;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' '){
                reverse(word.begin(), word.end());
                ans+=word;
                ans+=' ';
                word = "";
            }
            else{
                word += s[i];
            }
        }

        reverse(word.begin(),word.end());
        ans+=word;

        return ans;
    }
};