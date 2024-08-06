// Floyd Warshall is Multisource shortest path Algorithm

// run a loop for k = 0 to n-1
// dist[i][j]  = min(dist[i][j], dist[i][k] + dist[k][j])

// * Time Complexity: O(V^3)
// * Auxiliary Space: O(V^2)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {

        int n = matrix.size();

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int cur = matrix[i][j] == -1 ? 1e8 : matrix[i][j];
                    int a = matrix[i][k] == -1 ? 1e8 : matrix[i][k];
                    int b = matrix[k][j] == -1 ? 1e8 : matrix[k][j];

                    matrix[i][j] = min(cur, a + b);

                    if (matrix[i][j] >= 1e8)
                        matrix[i][j] = -1;
                }
            }
        }
        // to detect negative cycle we check for a negative value in the matrix. Although in the above case we are using -1 as a placeholder for infinity (no edge) so will need to check negative values other than -1
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortest_distance(matrix);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
