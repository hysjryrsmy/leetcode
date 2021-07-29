//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target 的那两个整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i]) == 1) {
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};
