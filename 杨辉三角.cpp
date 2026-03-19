//杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> c;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = c[i - 1][j - 1] + c[i - 1][j];
            }

            c.push_back(row);
        }
        return c;
    }
};
