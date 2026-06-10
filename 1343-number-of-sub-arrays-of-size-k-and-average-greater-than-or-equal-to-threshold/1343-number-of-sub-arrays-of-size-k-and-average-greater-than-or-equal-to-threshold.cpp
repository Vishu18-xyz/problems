class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();

        int start = 0; 
        int end = k-1;
        int sum = 0;
        int count = 0;

        for(int i = 0; i<k; i++){
            sum+=arr[i];
        }

        while(end<n){
            int average = sum/k;
            if(average < threshold){
                sum-=arr[start];
                end++;
                start++;
                if(end<n){
                sum+=arr[end];
                }
            }
            else{
                count++;
                sum-=arr[start];
                end++;
                start++;
                if(end<n){
                sum+=arr[end];
                }
            }
        }

        return count;
    }
};