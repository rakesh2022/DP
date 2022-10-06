/*
    link: https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

    video: https://www.youtube.com/watch?v=ww4V7vRIzSk

    when we aim to make opponent fail greedy will work
    but when to aim for make opponent fail + optimally win we use DP.


    video will be more helpful in this problem.

    here we are filling in diagonal manner

    why?
    as we want gap (length between 0, n-1) at a time constant but increasing 1 at a time
    also we want i and j to increase by 1 both at a time as both us and opponent will be making choices.

*/

// ----------------------------------------------------------------------------------------------------------------------- //
// Function to find the maximum possible amount of money we can win.
class Solution
{
public:
    int t[1000][1000];
    int solve(int arr[], int i, int j)
    {
        if (i > j)
            return 0;
        if (t[i][j] != -1)
            return t[i][j];
        int Ai = arr[i] + min(solve(arr, i + 2, j), solve(arr, i + 1, j - 1));
        int Aj = arr[j] + min(solve(arr, i + 1, j - 1), solve(arr, i, j - 2));
        return t[i][j] = max(Ai, Aj);
    }
    long long maximumAmount(int arr[], int n)
    {
        memset(t, -1, sizeof(t));
        solve(arr, 0, n - 1);
    }
};
//-------------------------------------------------------------------------------------------------------------------------------//
long long maximumAmount(int arr[], int n)
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
                dp[i][j] = arr[i];
            else if (gap == 1)
                dp[i][j] = max(arr[i], arr[j]);
            else
            {
                int a = arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]);
                int b = arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]);
                dp[i][j] = max(a, b);
            }
        }
    }
    return dp[0][n - 1];
}

// ----------------------------------------------------------------------------------------------------------------------- //