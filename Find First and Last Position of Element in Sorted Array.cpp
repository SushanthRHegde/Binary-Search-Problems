class Solution {
public:
    int lowerBound(vector<int>& nums, int x){
        int n = nums.size();
        int low = 0 , high = n - 1 ;
        int ans = n ;
        while( low <= high ) {
            int mid = (low + high)/2;            
            if(nums[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int upperBound(vector<int>& nums, int x){
        int n = nums.size();
        int low = 0 , high = n - 1 ;
        int ans = n ;
        while( low <= high ) {
            int mid = ( low + high )/2;
            if(nums[mid] > x){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums,target);
        //if the element is not present --> edge case
        if(lb == n || nums[lb] != target) return vector<int>{-1,-1};
        int ub = upperBound(nums,target);
        return vector<int>{lb, ub- 1};
    }
};
