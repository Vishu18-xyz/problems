class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        unordered_map<int,int> f;
        priority_queue<pair<int,int>> p;
        int n = barcodes.size();

        for(int i = 0; i<n; i++){
            f[barcodes[i]]++;
        }

        for(auto it = f.begin(); it != f.end(); it++){
           p.push({it->second,it->first});
        }

        vector<int> ans(n);
        
        int i = 0;
        while(!p.empty()){
            int a = p.top().first;
            int b = p.top().second;
            p.pop();

            while(a>0){
               if(i>n-1){
                i = 1;
               }
               ans[i] = b;
               i = i+2;
               a--;
            }
        }

        return ans;
    }
};