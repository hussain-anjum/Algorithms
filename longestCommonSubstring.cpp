// Write a program to find the longest common substring from two given strings.
#include <bits/stdc++.h>
using namespace std;

string longestCommonSubstring(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    int dp[n + 1][m + 1] = {0}; // Table initialized to 0
    int maxLen = 0, endIndex = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                    endIndex = i;
                }
            }
        }
    }
    return s1.substr(endIndex - maxLen, maxLen);
}

int main()
{
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    string lcs = longestCommonSubstring(s1, s2);
    cout << "Longest Common Substring: " << lcs << endl;
    cout << "Length: " << lcs.size() << endl;

    return 0;
}
