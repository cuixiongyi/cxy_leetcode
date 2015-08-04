class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        int idx = 1;
        int stridx = -1;
        for (int ii=0; ii < strs.size(); ++ii)
        {
            if (strs[ii].empty())
                continue;
            else
            {
                stridx = ii;
                break;
            }
                
        }
        if (stridx == -1)
            return "";
            
        string ret = "";
        while (1)
        {
            string prefix ( strs[stridx].begin(), strs[stridx].begin()+idx);
            bool found = true;
            for (int ii=0; ii < strs.size(); ++ii)
            {
                if (strs[ii].find(prefix) != 0)
                {
                    return ret;
                }
            }
            ++idx;
            ret = prefix;
            if (idx > strs[stridx].size())
                return ret;
        }
    }
};
