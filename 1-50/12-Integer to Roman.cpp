class Solution {
public:

const vector<string> thous_ {"","M","MM","MMM"};
const vector<string> hunds_ {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
const vector<string> tens_ {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const vector<string> ones_  {"","I","II","III","IV","V","VI","VII","VIII","IX"};

    string intToRoman(int num) {
        
        string ret {""};
        
        ret += thous_[num / 1000];
        ret += hunds_[ (num / 100) % 10];
        
        ret += tens_[ (num / 10) % 10];
        ret += ones_[ num % 10];
        
        return ret;
    }
};
