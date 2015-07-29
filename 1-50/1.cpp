#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>



int main()
{


	std::vector<int> num;
	int target = 0;

	std::ifstream fin("/home/xiongyi/repo/build/cxy_leetcode/files/1_in.txt");

	std::string line;
	//std::getline(fin, line);
	std::getline(std::cin, line);
	auto brace_start = line.find("{");
	auto brace_end = line.find("}");
	if (brace_end == std::string::npos)
	{
		throw std::runtime_error("can't find corresponding braces");
	}

	std::string num_string(line.begin()+brace_start+1, line.begin()+brace_end);

	std::stringstream ss(num_string);
	int tmp;

	while (ss>>tmp)
	{
		num.push_back(tmp);
		if (ss.peek() == ',' || ss.peek() == ' ')
			ss.ignore();
	}

	/// inpute target=
	auto target_ptr = line.find("target=");
	std::string target_str (line.begin()+target_ptr+7, line.end());
	std::stringstream ss_tar(target_str);
	ss_tar>>target;
	std::vector<int> num_sort(num);

	std::sort (num_sort.begin(), num_sort.end());
/*
for (int i = 0; i < num.size(); ++i)
{
	std::cout<<num[i]<<"  ";
}
	std::cout<<"target = "<<target<<std::endl;

**/

	int ii_idx = 0;
	int jj_idx = 0;
	bool success_flag = false;
	for (int ii = 0; ii < num_sort.size(); ++ii)
	{
		for (int jj = ii+1; jj < num_sort.size(); ++jj)
		{
			if (num_sort[ii] + num_sort[jj] == target)
			{
				ii_idx = ii;
				jj_idx = jj;
				success_flag = true;

				break;
			}
		}
		if (success_flag)
		{
			break;
		}
	}
	for (int ii = 0; ii < num.size(); ++ii)
	{
		if (num[ii] == num_sort[ii_idx])
		{
			ii_idx = ii;
			break;
		}
	}
	for (int ii = 0; ii < num.size(); ++ii)
	{
		if (num[ii] == num_sort[jj_idx])
		{
			jj_idx = ii;
			break;
		}
	}
	if (ii_idx > jj_idx)
	{
		int tmp(jj_idx);
		jj_idx = ii_idx;
		ii_idx = tmp;
	}
	std::cout<<"index1="<<ii_idx+1<<", "<<"index2="<<jj_idx+1<<std::endl;
	return 0;
}