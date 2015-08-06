class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int close = INT_MAX;
        int size = nums.size();
        int closet = 0;
        sort(nums.begin(), nums.end());
        for (int ii = 0; ii < size-2; ++ii)
        {
            int lo = ii+1;
            int hi = size-1;
            
            
            while (lo < hi)
            {
                int tmp = nums[lo] + nums[hi] + nums[ii] - target;
                if (abs(tmp) < abs(close))
                {
                    closet = nums[lo] + nums[hi] + nums[ii];
                    close = tmp;
                    
                }
                else if (tmp < 0)
                    
                {
                    
                    while (lo < hi && nums[lo] == nums[lo+1]) ++lo;
                    ++lo;
                }
                else 
                {
                    while (lo < hi && nums[hi] == nums[hi-1]) --hi;
                    --hi;
                }
            }
            while (ii < size-1 && nums[ii] == nums[ii+1]) ++ii;
        }
        return closet;
    }
};
