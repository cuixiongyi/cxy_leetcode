class Solution {
public:
static map<string, int> tab;
    int romanToInt(string s) {
        Solution::tab[""] = 0;
 Solution::tab["M"] = 1000;
 Solution::tab["MM"] = 2000;
 Solution::tab["MMM"] = 3000;
 
 Solution::tab["C"] = 100;
 Solution::tab["CC"] = 200;
 tab["CCC"] = 300;
 tab["CD"] = 400;
 tab["D"] = 500;
 tab["DC"] = 600;
 tab["DCC"] = 700;
 tab["DCCC"] = 800;
 tab["CM"] = 900;
 
 tab["X"] = 10;
 tab["XX"] = 20;
 tab["XXX"] = 30;
 tab["XL"] = 40;
 tab["L"] = 50;
 tab["LX"] = 60;
 tab["LXX"] = 70;
 tab["LXXX"] = 80;
 tab["XC"] = 90;
 
 tab["I"] = 1;
 tab["II"] = 2;
 tab["III"] = 3;
 tab["IV"] = 4;
 tab["V"] = 5;
 tab["VI"] = 6;
 tab["VII"] = 7;
 tab["VIII"] = 8;
 tab["IX"] = 9;
        string thous = "";
        string hunds = "";
        string tens = "";
        string ones = "";
        bool acpt_thous = true;
        bool acpt_hunds = true;
        bool acpt_tens = true;
        bool acpt_ones = true;
        for (int ii = 0; ii < s.size(); ++ii)
        {
            if (s[ii] == 'M' && acpt_thous)
            {
                thous += s[ii];
                continue;
            }   
            if ((s[ii] == 'C' || s[ii] == 'D' || s[ii] == 'M') && acpt_hunds)
            {
                hunds += s[ii];
                acpt_thous = false;
                continue;
            }   
            if ((s[ii] == 'X' || s[ii] == 'L' || s[ii] == 'C') && acpt_tens)
            {
                tens += s[ii];
                acpt_hunds = false;
                continue;
            }
            if (s[ii] == 'I' || s[ii] == 'V' || s[ii] == 'X')
            {
                ones += s[ii];
                acpt_tens = false;
                continue;
            }
        }
        int ret = tab[thous] + tab[hunds] + tab[tens] + tab[ones];
        return ret;
    }
};


 map<string, int> Solution::tab;
 
