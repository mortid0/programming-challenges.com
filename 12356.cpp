#include <array>
#include <cstdio>

const size_t max_line = 200000;

struct Elem
{
    int left;
    int right;
    bool killed = false;
};

int main()
{
    int S,B;
    std::array<Elem, max_line> unit;
    while (scanf("%d %d", &S, &B) == 2)
    {
       if (S == 0 && B == 0) {break;}
       for (int i = 1; i < S+1; ++i)
       {
           unit[i].left = i-1;
           unit[i].right = i+1;
           unit[i].killed = false;
       }
       unit[0].killed = true;
       unit[S+1].killed = true;
       while (B > 0)
        {
            int L, R;
            scanf("%d %d", &L, &R);
            unit[L].killed = true;
            unit[R].killed = true;
            
            int curr_l = unit[L].left;
            while (unit[curr_l].killed && curr_l > 0) {curr_l = unit[curr_l].left;}
            unit[R+1].left = curr_l;
            
            int curr_r = unit[R].right;
            while (unit[curr_r].killed && curr_r <= S) {curr_r = unit[curr_r].right;}
            unit[L-1].right = curr_r;

            unit[R].right = curr_r;
            unit[R].left = curr_l;
            unit[L].left = curr_l;
            unit[L].right = curr_r;

            if (!unit[curr_l].killed)
            {
                printf("%d ", curr_l);
            }
            else
            {
                printf("* ");
            }
            if (!unit[curr_r].killed)
            {
                printf("%d\n", curr_r);
            }
            else
            {
                printf("*\n");
            }
            --B;
        }
        printf("-\n");
    }
}
