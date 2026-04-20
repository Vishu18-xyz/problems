class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans  = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i = 0; i<n1; i++){
            int start = i;
            int end = n2-1;
            int index = 0;

            while(start <= end){
                int mid = (start+end)/2;
                if(nums2[mid] < nums1[i]){
                    end = mid-1;
                }
                else if(nums2[mid] >= nums1[i]){
                    index = mid;
                    start = mid+1;
                }
            }
            ans = max(ans,index-i);
        }
        return ans;
   }
};