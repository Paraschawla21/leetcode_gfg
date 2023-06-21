class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        for (int c = 1; c <= rowIndex; c++)
        {
            for (int i = c - 1; i > 0; i--)
            {
                row[i] = row[i] + row[i - 1];
            }
        }
        return row;
    }
};