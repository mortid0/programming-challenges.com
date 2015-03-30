#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

bool jolly(std::vector<int>& v)
{
	if (v.size() < 2) {return true;}
	for (int i = 0; i < v.size() -1; i++)
	{
		v[i] = fabs(v[i+1] - v[i]);
	}
	v.pop_back();
	std::sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] - v[i-1] != 1) {return false;}
	}
	return true;
}

int main(int argc, char* argv[])
{
	int c{1};
	while (std::cin >> c)
	{
		std::vector<int> v(c);
		for (int i = 0; i < c; ++i)
		{
			std::cin >> v[i];
		}
		std::cout << (jolly(v) ? "Jolly" : "Not jolly") << std::endl;
	}
	return 0;
}

