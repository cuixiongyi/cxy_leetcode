class Solution {
public:
    string convert(string s, int numRows) {
      if (numRows == 1)
        return s;
      std::vector<std::string> vecstr(numRows, "");
      std::string ret = "";
      int ii = 0;
      int vec_idx = 0;
      bool idx_inc = true;
      while (ii < s.size())
      {
          vecstr[vec_idx] += s[ii];
          
          ++ii;
          if (vec_idx == 0)
          {
              idx_inc = true;
          }
          else if (vec_idx == numRows-1)
          {
              idx_inc = false;
          }
          if (idx_inc)
          {
              ++vec_idx;
          }
          else 
          {
              --vec_idx;
          }
          
      }
      
      for (int jj = 0; jj < vecstr.size(); ++jj)
      {
          ret += vecstr[jj];
      }
      
      return ret;
    }
};
