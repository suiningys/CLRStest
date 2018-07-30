#include "dynamicProgranmming.h"

int cutRod(vector<int> p, int n)
{
    if(n==0)
        return 0;
    int q = -1;
    for(int ii = 1; ii<=n;++ii)
    {
        q = max(q, p[ii-1]+cutRod(p,n-ii));
    }
    return q;
}
