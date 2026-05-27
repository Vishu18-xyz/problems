class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> upper(26,0);
        vector<int> lower(26,0);
        vector<int> upperfirst(26,0);
        vector<int> lowerlast(26,0);

        for(int i = 0; i<word.size(); i++){

            if(word[i]>='A' && word[i]<='Z'){
                if(upper[word[i]-'A'] == 0){
                    upperfirst[word[i]-'A'] = i;
                }
                upper[word[i]-'A']++;
            }
            else{
                lowerlast[word[i]-'a'] = i;
                
                lower[word[i]-'a']++;
            }
        }

        int count = 0;

        for(int i = 0; i<26; i++){
            if(lower[i]!=0 && upper[i]!=0){
                if(lowerlast[i]<upperfirst[i]){
                    count++;
                }
            }
        }

        return count;

    }
};