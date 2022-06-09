#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    set<int> s;
    for (auto nums : arr)
    {
        s.insert(nums);
    }
    int longestStreak = 0;
    for (auto nums : arr)
    {
        if (!s.count(nums - 1))
        {
            int currentStreak = 1;
            int currentNum = nums;
            while (s.count(currentNum + 1))
            {
                currentStreak++;
                currentNum++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}

int main()
{
    vector<int> arr{100, 200, 1, 2, 3, 4};
    int n = 6;
    int lon = lengthOfLongestConsecutiveSequence(arr, n);
    cout << "The longest consecutive sequence is " << lon << endl;
    return 0;
}