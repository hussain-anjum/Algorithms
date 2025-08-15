// Develop a program to implement the well-known coin exchange problem.
#include <iostream>
using namespace std;

int minCoins(int coins[], int m, int amount)
{
    int dp[1000];
    int INF = 999999;

    for (int i = 0; i <= amount; i++)
        dp[i] = INF;
    dp[0] = 0;

    // Compute minimum coins
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i])
            {
                dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    if (dp[amount] == INF)
        return -1;
    return dp[amount];
}

int main()
{
    int m, amount, coins[100];
    cout << "Enter number of coin types: ";
    cin >> m;

    cout << "Enter coin denominations: ";
    for (int i = 0; i < m; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    int res = minCoins(coins, m, amount);

    if (res == -1)
        cout << "Amount cannot be made with given coins\n";
    else
        cout << "Minimum coins required: " << res << endl;

    return 0;
}
