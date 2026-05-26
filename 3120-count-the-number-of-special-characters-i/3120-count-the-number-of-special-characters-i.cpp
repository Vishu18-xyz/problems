class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>upper(26,0);
        vector<int>lower(26,0);
        int count = 0;

        int n = word.size();

        for(int i = 0; i<n; i++){
            if(word[i]>='A' && word[i]<='Z'){
                upper[word[i]-'A']++;
            }
            else{
                lower[word[i]-'a']++;
            }
        }

        for(int i = 0; i<26; i++){
            if( upper[i] != 0 && lower[i] !=0){
                count++;
            }
        }
        return count;
    }
};