class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //edge cases
        if(n == 1 ) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n - 2]) return n - 1;

        int low = 1 , high = n - 2;
        while( low <= high){
            int mid = ( low + high)/2;
            //if it satisy the peak element condition
            if((nums[mid - 1] < nums[mid]) && (nums[mid] > nums[mid +1]))
                return mid;

            if(nums[mid] > nums[mid - 1]) low = mid + 1 ;
            else high = mid - 1;
        }
        return -1;
    }
};
