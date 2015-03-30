#include <iostream>
#include <unordered_map>

int main()
{
    int N;
    std::cin >> N;
    for (int n = 0; n < N; ++n)
    {
        int K;
        std::cin >> K;
        std::unordered_map<char, int> table;
        for (int k = 0; k < K; ++k)
        {
            char c;
            int val;
            std::cin >> c >> val;
            table[c] = val;
        }
        int M;
        std::cin >> M;
        unsigned long sum{0};
        std::cin.ignore();
        for (int m = 0; m < M; ++m)
        {
            char c;
            while (std::cin.get(c))
            {
                if ((c == '\n') || (c == '\r')) {break;}
                sum += table[c];
            }
        }
        printf("%ld.%02ld$\n",sum / 100, sum % 100);
    }
}
