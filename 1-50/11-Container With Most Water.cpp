class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int lidx = 0;
        int ridx = size -1;
        int maxarea = 0;
        
        while (lidx < ridx)
        {
            maxarea = max(maxarea, (ridx-lidx) * min(height[lidx],height[ridx]));
            if (height[lidx] > height[ridx])
            {
                --ridx;
            }
            else
                ++lidx;
        }
        
        return maxarea;
    }
};
