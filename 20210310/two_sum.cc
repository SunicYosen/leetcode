/*
1. 两数之和 

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

你可以按任意顺序返回答案。

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]

提示：
2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int v_size = nums.size();

        int target_index0 = 0;
        int target_index1 = 1;
        int target_value0;
        int target_value1;

        for (target_index0=0; target_index0 < v_size-1; target_index0 ++){
            target_value0 = nums[target_index0];
            for(target_index1=target_index0+1; target_index1 < v_size; target_index1 ++){
                target_value1 = nums[target_index1];
                if((target_value0 + target_value1) == target){
                    result.push_back(target_index0);
                    result.push_back(target_index1);
                    return result;
                }
            }
        }

        return result;
    }
};

int main(){
    Solution solution1;
    vector<int> nums = {3, 2, 3, 4};
    int target       = 5;

    vector<int> result;

    result = solution1.twoSum(nums, target);

    std::cout << result[0] << ',' << result[1] << std::endl;
}