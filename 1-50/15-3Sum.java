public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int size = nums.length;
        List<List<Integer>> ret =  new LinkedList<>(); 
        if (size <= 2)
            return ret;
            
        Arrays.sort(nums);
        
        
        for (int ii = 0; ii < size - 2; ++ii)
        {
            int start = ii+1; 
            int end = size-1;
            while (start < end)
            {
                if (nums[start] + nums[ii] + nums[end] == 0 )
                {
                    ret.add(Arrays.asList(nums[ii], nums[start], nums[end]));
                    
                    while (start < end && nums[start] == nums[start+1]) ++start;
                    
                    while (start < end && nums[end] == nums[end-1]) --end;
                    ++start;
                    --end;
                    
                }
                else if (nums[start] + nums[ii] + nums[end] < 0)
                    ++start;
                else 
                    --end;
            }
            while ( ii < size-1 && nums[ii] == nums[ii+1]) ++ii;
        }
        
        return ret;
    }
}
