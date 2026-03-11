class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int length = arr.size();
        int left = 0;
        int right = 0;
        int myMax = 0;
        int idxMax = -1;
        vector<int> ans;
        while(right < length){
            if(arr[right] > myMax){
                myMax = arr[right];
                idxMax = right;
            }
            if(right - left + 1 == k){
                if(idxMax < left){
                    myMax = 0;
                    for(int i = left; i<=right; i++){
                        if(arr[i] > myMax){
                            myMax = arr[i];
                            idxMax = i;
                        }
                    }
                }
                ans.push_back(myMax);
                left++;
            }
            right++;
        }
        return ans;
    }
};
