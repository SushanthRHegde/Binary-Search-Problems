//Using Built in function --> sqrt() 

class Solution {
public:
    int mySqrt(int x) {
        int ans = sqrt(x);
        return ans;
    }
};


// Using the Binary Search Approach 


class Solution {
public:
    int mySqrt(int x) {
        if (x < 1) return 0;
        int low = 1, high = x;
        while (low <= high) {
            int mid = low + (high - low) / 2;  // This avoids overflow
            long long val = (long long) mid * mid;  // Cast mid to long long before multiplication
            if (val <= x) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};
