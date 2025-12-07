#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum sum submatrix
int maxSumSubmatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    long long totalSum = 0;
    cout << n << " "<< m << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long topLeft = (long long)(i + 1) * (j + 1);
            long long bottomRight = (long long)(m - i) * (n - j);
            long long count = topLeft * bottomRight;
            totalSum += (long long)matrix[i][j] * count;
            cout << topLeft << " "<< bottomRight << " "<< count << " "<< totalSum << endl; 
        }
    }

    return totalSum; 
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}};

    cout << "Maximum Sum Submatrix: " << maxSumSubmatrix(matrix) << endl;
    return 0;
}