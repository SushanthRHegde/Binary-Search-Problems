//Finding the unique element using BRUTE FORCE --> Using unordered_map 
// Tc--> O(2N) SC--> O(N)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        int unique = -1;
        for(int i = 0; i< n;i++){
            mpp[nums[i]]++;

        }
        for(int i = 0; i < n;i++){
                if(mpp[nums[i]] == 1){
                 unique = nums[i];
                 break;
            }
        }
        return unique;
    }
};

//Using the binary search --> TC --> O(N)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        //understand the edge case 
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1 , high = n - 2;
        while( low <= high ){
            int mid = ( low + high)/2;
            //if the mid element is the single
            if((nums[mid] != nums[mid - 1])&& (nums[mid] != nums[mid +1 ]))
                return nums[mid];

            //eliminating the left or right part --> (even , odd)

            if((mid % 2 == 1 && nums[mid] == nums[mid - 1])|| 
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) 
            low = mid + 1;
            else high = mid - 1;

        }
        return - 1;

    }
};
