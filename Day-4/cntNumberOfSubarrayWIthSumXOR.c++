#include <bits/stdc++.h>
using namespace std;

int optimalSol(vector<int> a, int k)
{
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int xorr = 0;
        for (int j = i; j < n; j++)
        {

            xorr = xorr ^ a[j];

            if (xorr == k)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> ar = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = optimal(ar, k);
    cout << "ans is : "
         << ans << "\n";
    return 0;
}