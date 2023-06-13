#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = {start[i], end[i]};
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);
    int cnt = 1;
    int endTime = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > endTime)
        {
            cnt++;
            endTime = v[i].second;
        }
    }
    return cnt;
}
int main()
{
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};
    maxMeetings(start, end, n);
    return 0;
}