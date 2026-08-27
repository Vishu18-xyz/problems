class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()){
            return false;
        }
        
        unordered_map<int, int> count1;
        unordered_map<int,int> count2;

        for(int i = 0; i<s1.size(); i++){
            count1[s1[i]]++;
            count2[s2[i]]++;
        }

        int left = 0; 
        int right = s1.size();

        while(right<s2.size()){
            if(count1 == count2){
                return true;
            }

            count2[s2[right]]++;
            count2[s2[left]]--;

            if(count2[s2[left]] == 0){
                count2.erase(s2[left]);
            }

            left++;
            right++;
        }

        return count1 == count2;

    }
};