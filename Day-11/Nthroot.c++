#include <bits/stdc++.h>
using namespace std;

int getNthRoot(int n, int m)
{
    int left = 0;
    int right = m;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (pow(mid, n) == m)
            return mid;
        else if (pow(mid, n) > m)
            right = m - 1;
        else
            left = mid + 1;
    }
    return -1;
    
}
int main()
{
    int n = 2, m = 16;

    int ans = getNthRoot(n, m);
    return ans;
}
