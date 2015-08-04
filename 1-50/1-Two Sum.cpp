class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> vec;    
        for (int ii = 0; ii < nums.size(); ++ii)
        {
            if (hash.find(target - nums[ii]) != hash.end())
            {
                int tmp = target - nums[ii];
                
                if (ii+1 <  hash[target - nums[ii]]+1)
                {
                    vec.push_back(ii+1);
                    vec.push_back(hash[target - nums[ii]]+1);
                }
                else
                {
                    vec.push_back(hash[target - nums[ii]]+1);
                    vec.push_back(ii+1);
                    
                }
                
                return vec;
            }
            
            hash[nums[ii]] = ii;
        }
        
        return vec;
    }
};
