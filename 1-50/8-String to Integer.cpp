class Solution {
public:
    bool isNum(const char& c)
    {
    
        if (c - '0' >= 0 && c - '9' <= 0)
            return true;
        else 
            return false;
    }
    bool isLegal(const char& c)
    {
        
        if (c != ' ')
            isAcceptSpace_ = false;
        if (c == ' ' && isAcceptSpace_)
            return true;
        else if ((c == '+' || c == '-') && isAcceptSign_)
        {
            isAcceptSign_ = false;
            isAcceptSpace_ = false;
            if (c == '+')
                signPosi_ = true;
            else if (c == '-')
                signPosi_ = false;
            return true;
        }
        else if (isNum(c))
        {
            isAcceptSign_ = false;
            isAcceptSpace_ = false;
            return true;
        }
        else 
            return false;
    }
    bool isAcceptSpace_;
    bool isAcceptSign_;
    bool signPosi_;
    //bool 
    int myAtoi(string str) {
        isAcceptSpace_ = true;
        isAcceptSign_ = true;
        signPosi_ = true;
        int ii = 0;
        int size = str.size();
        long long ret = 0;
        while (1)
        {
            if (ii == size)
                break;
            if ( ! isLegal(str[ii]))
            {
                return (signPosi_ ? ret : -ret);
            }
            else if ( ! isNum(str[ii]))
            {
                ++ii;
                continue;
            }
            else
            {
                int tmp = str[ii] - '0';
                ret = ret*10 + tmp;
                if (ret > INT_MAX && signPosi_)
                    return INT_MAX;
                if (-ret < INT_MIN && !signPosi_)
                    return INT_MIN;
                ++ii;
                continue;
            }
            
            
        }
        return  (signPosi_ ? ret : -ret);
    }
};
