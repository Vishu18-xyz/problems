class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int first = 0;
        int second = 0; 

        string ans = "";

        int n1 = word1.size();
        int n2 = word2.size();

        while(first<n1 && second<n2){
            ans += word1[first];
            ans += word2[second];
            first++;
            second++;
        }
        while(first<n1){
            ans = ans+word1[first];
            first++;
        }

        while(second<n2){
            ans = ans+word2[second];
            second++;
        }
        return ans;
    }
};