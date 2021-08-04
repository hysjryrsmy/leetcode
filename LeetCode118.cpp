
//118：杨辉三角

//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。

//示例 1:
//输入: numRows = 5
//输出 : [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]

//示例 2 :
//	输入 : numRows = 1
//	输出 : [[1]]


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        /*
        if (numRows == 0) {
            return ans;
        }
        */
        ans.push_back(vector<int>{1});
        for (int i = 2; i <= numRows; i++) {
            vector<int> v(1, 1);
            for (int j = 1; j <= i - 2; j++) {
                v.push_back(ans[i - 2][j - 1] + ans[i - 2][j]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};
