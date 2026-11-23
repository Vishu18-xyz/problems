class Solution {
public:
    int solve(int index, vector<string>&words, vector<char>&letters, vector<int>&score, vector<int>&freq){
        if(index == words.size()){
            return 0;
        }

        int skip = solve(index+1,words,letters,score,freq);

        int wordScore = 0;
        vector<int> used(26, 0);

        bool possible = true;

        for (char ch : words[index]) {
            int c = ch-'a';

            used[c]++;
            wordScore += score[c];

            if (used[c] > freq[c]) {
                possible = false;
                break;
            }
        }

        int take = 0;

        if (possible) {
            for (int i = 0; i<26; i++) {
                freq[i] -= used[i];
            }

            take = wordScore + solve(index + 1, words, letters, score,freq);

            for (int i = 0; i < 26; i++) {
                freq[i] += used[i];
            }
        }

        return max(skip, take);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);

        for(int i = 0; i<letters.size(); i++){
            freq[letters[i]-'a']++;
        }
        return solve(0,words,letters,score,freq);
    }
};