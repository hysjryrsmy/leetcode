
//967:连续差相同的数字

//返回所有长度为 n 且满足其每两个连续位上的数字之间的差的绝对值为 k 的 非负整数 。
//请注意，除了 数字 0 本身之外，答案中的每个数字都 不能 有前导零。例如，01 有一个前导零，所以是无效的；但 0 是有效的。
//你可以按 任何顺序 返回答案。

//示例 1：
//输入：n = 3, k = 7
//输出：[181, 292, 707, 818, 929]
//解释：注意，070 不是一个有效的数字，因为它有前导零。

//示例 2：
//输入：n = 2, k = 1
//输出：[10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98]


class Solution {
public:
    vector<int> ans;
    void func(long long now, int left, int k) {
        if (left == 0) {
            ans.push_back((int)now);
            return;
        }
        int t = now % 10;
        if (t - k >= 0) {
            func(now * 10 + t - k, left - 1, k);
        }
        if (k != 0 && t + k < 10) {
            func(now * 10 + t + k, left - 1, k);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; i++) {
            func(i, n - 1, k);
        }
        return ans;
    }
};