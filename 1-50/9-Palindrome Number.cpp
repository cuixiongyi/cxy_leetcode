class Solution {
public:
    bool isPalindrome(int x) {
        long mag = 1;
        long xtmp = x;
        
        if (x < 0)
            return false;
        
        while (1)
        {
            if (xtmp / mag < 10)
                break;
            mag = mag * 10;
            
        }
        
        
        
        while (mag >= 1)
        {
            int l = xtmp / mag;
            int r = xtmp % 10;
            if (l != r)
                return false;
            xtmp = xtmp % mag / 10;
            mag /= 100;
        }
        return true;
        
    }
    
};
