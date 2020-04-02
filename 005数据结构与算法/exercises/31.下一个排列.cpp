/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.95%)
 * Likes:    433
 * Dislikes: 0
 * Total Accepted:    52K
 * Total Submissions: 157.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
                int len = nums.size();

        int i = len-2;
        int j = len-1;
        int k = len-1;
        for(;i >= 0 && nums[i] >= nums[j];--i,--j);
        if(i>=0){
            for(;nums[i] >= nums[k];--k);
            swap(nums[i],nums[k]);
        }
        i = j;
        j = len-1;
        for(; i < j; ++i, --j){
            swap(nums[i],nums[j]);
        }
    }

    void swap(int &a,int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};
// @lc code=end

