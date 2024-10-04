#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Function to rotate the matrix by 90 degrees clockwise
void rotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Step 1: Transpose the matrix (swap elements symmetrically across the diagonal)
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row to complete the 90-degree clockwise rotation
    for (int i = 0; i < n; ++i)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Driver code
int main()
{
    // Example matrix (3x3 matrix)
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // Output the original matrix
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    // Rotate the matrix by 90 degrees clockwise
    rotateMatrix(matrix);

    // Output the rotated matrix
    cout << "\nMatrix after 90-degree clockwise rotation:" << endl;
    printMatrix(matrix);

    return 0;
}
