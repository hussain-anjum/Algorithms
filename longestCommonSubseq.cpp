// Write a program to find the longest common subsequence from two given strings.
#include <bits/stdc++.h>
using namespace std;

int LCS(char X[], char Y[], int m, int n, char lcsSeq[])
{
    int dp[100][100];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int index = dp[m][n];
    lcsSeq[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcsSeq[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return dp[m][n];
}

int main()
{
    char X[100], Y[100], lcsSeq[100];
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int m = 0, n = 0;
    while (X[m] != '\0')
        m++;
    while (Y[n] != '\0')
        n++;

    int length = LCS(X, Y, m, n, lcsSeq);

    cout << "Length of LCS: " << length << endl;
    cout << "LCS: " << lcsSeq << endl;

    return 0;
}
