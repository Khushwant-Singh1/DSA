#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{

    sort(stalls.begin(), stalls.end());

        int s = 0;
    int maxi = -1;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }return ans;
}

int main()
{
    int n, k;

    cout << "Enter the number of stalls: ";
    cin >> n;
    cout << "Enter the number of cows: ";
    cin >> k;

    vector<int> stalls(n);
    cout << "Enter the positions of the stalls: ";
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    int result = aggressiveCows(stalls, k);
    cout << "The largest minimum distance between cows is: " << result << endl;

    return 0;
}