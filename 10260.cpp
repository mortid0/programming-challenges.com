#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::string str;
    std::unordered_map<char,int> m = {{'B',1}, {'F',1}, {'P',1}, {'V',1}, 
                                      {'C',2}, {'G',2},{'J',2},{'K',2}, {'Q',2} ,{'S', 2}, {'X',2}, {'Z', 2},
                                      {'D',3}, {'T',3},
                                      {'L',4},
                                      {'M',5}, {'N',5},
                                      {'R',6}};
    while (std::cin >> str)
    {
        int prev{-1};
        for (char c : str)
        {
            const auto code = m.find(c);
            if ( code == m.end() ) {prev = -1;continue;}
            if ( code->second == prev) {continue;}
            std::cout << code->second;
            prev = code->second;
        }
        std::cout << std::endl;
    }
}
