#include <iostream>
#include <array>
#include <algorithm>
#include <cassert>
#include <vector>

int main()
{
    int T;
    std::cin >> T;
    std::vector<int> res;
    while (T > 0)
    {
        int N;
        std::cin >> N;
        assert(N < 3651);
        int P;
        std::cin >> P;
        std::array<bool, 7055> hartal;
        hartal.fill(false);
        while (P > 0)
        {
            int curr_h;
            std::cin >> curr_h;
            for (int i = 0; i < N/curr_h + 1; ++i)
            {
                hartal[i*curr_h] = true;
            }
            --P;
        }
        for (int i = 1; i <= N/7 + 1; ++i)
        {
            hartal[i*7] = false;
            hartal[i*7-1] = false;
        }
        res.push_back(std::count(hartal.begin()+1, hartal.begin() + N + 1, true));
        --T;
    }
    for (const auto& v : res)
    {
        std::cout << v << std::endl;
    }
}
