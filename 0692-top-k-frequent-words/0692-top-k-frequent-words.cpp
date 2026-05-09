class Solution {
public:

    struct cmp {

        bool operator()(pair<int,string> a,
                        pair<int,string> b) {

            if(a.first == b.first){
                return a.second > b.second;
            }

            return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int> freq;

        for(int i = 0; i<n; i++){
            freq[words[i]]++;
        }

         priority_queue<pair<int,string>,
                       vector<pair<int,string>>,
                       cmp> p;

        for(auto it = freq.begin(); it != freq.end(); it++){
            p.push({it->second,it->first});
        }

        vector<string> ans;
        
        for(int i = 0; i<k; i++){
            string maxfreq = p.top().second;
            p.pop();

            ans.push_back(maxfreq);
        }

        return ans;
    }
};