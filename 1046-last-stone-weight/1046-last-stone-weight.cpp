class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;

        for(int i = 0; i<stones.size(); i++){
            p.push(stones[i]);
        }
        
        while(p.size()>1){
            int wieght = p.top();
            p.pop();
            wieght = wieght - p.top();
            p.pop();

            if(wieght){
                p.push(wieght);
            }
        }

        return p.empty() ? 0 : p.top();
    }
};