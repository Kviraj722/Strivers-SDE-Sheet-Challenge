#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> arr)
{

    // size of the giarren array:
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        int cnt = 0;
        for (int j = 0; j < n; j++)
        {

            if (arr[j] == arr[i])
            {
                cnt++;
            }
        }
        if (cnt > (n / 2))
            return arr[i];
    }

    return -1;
}

int betterSol(vector<int> arr)
{

    // size of the giarren array:
    int n = arr.size();

    // declaring a map:
    map<int, int> mpp;

    // storing the elements with its occurnce:
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // searching for the majority element:
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }

    return -1;
}

int optimal(vector<int> arr)
{

    int n = arr.size();
    int cnt = 0;
    int el;

    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = arr[i];
        }
        else if (el == arr[i])
            cnt++;
        else
            cnt--;
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
            cnt1++;
    }

    if (cnt1 > (n / 2))
        return el;
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    // int ans = bruteForce(arr);
    // int ans = betterSol(arr);
    int ans = optimal(arr);

    cout << "The majority element is: " << ans << endl;
    return 0;
}