#include <bits/stdc++.h>
using namespace std;

int optimalSol(str)
{
    vector<int> mpp(256, -1);
    int n = s.length();
    int maxLen = 0;
    int right = 0, left = 0;
    while (right < n)
    {
        if (mpp[s[right]] != -1)
            left = max(mpp[s[right]] + 1, left);
        mpp[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
}
int main()
{
    string str = "takeUforward";

    cout << " length is -> " << optimalSol(str);
    return 0;
}