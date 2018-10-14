vector <int> SumOverSubsets (vector <int>& a, int n)
{
    vector <vector <int>> dp ((1 << n), vector <int> (n + 1));
    for (int i = 0; i < (1 << n); i++)
        dp[i][0] = a[i];
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j + 1] = dp[i][j];
            if (Bit (i, j) == 1)
                dp[i][j + 1] += dp[i ^ (1 << j)][j];
        }
    }
    vector <int> b ((1 << n));
    for (int i = 0; i < (1 << n); i++)
        b[i] = dp[i][n];
    return b;
}
