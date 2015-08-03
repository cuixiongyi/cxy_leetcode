class Solution {
public:
    int reverse(int x) {
        if (0 == x)
            return 0;
        long long xx = x;
        /// sign      true if x < 0
        bool sign = (xx < 0 ? true : false);
        if (sign)
        {
            xx = -xx;
        }
        long long int ret = 0;
        long long int mag = 10;
        while (1)
        {
            if (xx == 0)
                break;
            int tmp = xx % mag;
            
            
            ret = ret * 10 +tmp / (mag/10);
            if (ret > INT32_MAX && ! sign)
                return 0;
            if (-ret < INT32_MIN && sign)
                return 0;
            mag = mag*10;
            xx = xx - tmp;
        }
        
        if (sign)
        {
            ret = -ret;
        }
        return ret;
    }
};
