#include <bits/stdc++.h>
using namespace std;
int bruteForceSol(double x, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = ans * x;
    }
    return ans;
}

double optimalSol(double x, int n)
{
    double ans = 1.0;
    long long nn = n;

    if (nn < 0)
    {
        nn = -1 * nn;
    }

    while (nn != 0)
    {
        if (nn % 2)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }
    // if n is negative
    if (n < 0)
    {
        ans = 1.0 / ans;
    }

    return ans;
}
int main()
{
    cout << "Brute force -> " << bruteForceSol(2, 10) << endl;
    cout << "Optimal ->  " << optimalSol(2, 10);
}