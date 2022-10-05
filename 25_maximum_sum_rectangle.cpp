/*
    link: https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0#
    video: https://www.youtube.com/watch?v=kKEX4P53MyY
*/

// ----------------------------------------------------------------------------------------------------------------------- //
class Solution
{
public:
    int kadane(int A[], int n)
    {
        int res = A[0], sum = A[0];
        for (int i = 1; i < n; i++)
        {
            sum += A[i];
            if (sum < A[i])
                sum = A[i];
            res = max(sum, res);
        }
        return res;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {
        int sum[R];

        int ans = INT_MIN;
        for (int c = 0; c < C; c++)
        {
            memset(sum, 0, sizeof(sum));
            for (int cc = c; cc < C; cc++)
            {
                for (int r = 0; r < R; r++)
                {
                    sum[r] += M[r][cc];
                }
                ans = max(ans, kadane(sum, R));
            }
        }
        return ans;
    }
};
