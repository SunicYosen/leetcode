/*
4. 寻找两个正序数组的中位数

给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

示例 3：
输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000

示例 4：
输入：nums1 = [], nums2 = [1]
输出：1.00000

示例 5：
输入：nums1 = [2], nums2 = []
输出：2.00000

提示：
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size   = nums1.size();
        int nums2_size   = nums2.size();
        int total_nums   = nums1_size + nums2_size;
        int pop_nums_all = ((total_nums + 1)/2 - 1); 

        int nums1_index  = 0;
        int nums2_index  = 0;
        int pop_nums     = 0;

        int median_num1;
        int median_num2;

        bool nums1_empty = 0;
        bool nums2_empty = 0;

        for(;;){
            if(nums1_index >= nums1_size){
                nums1_empty = 1;
                break;
            }

            if(nums2_index >= nums2_size){
                nums2_empty = 1;
                break;
            }

            if(pop_nums >= pop_nums_all){
                break;
            }

            if(nums1[nums1_index] > nums2[nums2_index]){
                nums2_index ++;
            }
            else{
                nums1_index ++;
            }
            pop_nums ++;

            if(nums1_index >= nums1_size){
                nums1_empty = 1;
                break;
            }

            if(nums2_index >= nums2_size){
                nums2_empty = 1;
                break;
            }

            if(pop_nums >= pop_nums_all){
                break;
            }

        }

        int extra_pop_nums1 = pop_nums_all - pop_nums;
        int extra_pop_nums2 = total_nums/2 - pop_nums;
        if(nums1_empty){
            median_num1 = nums2[nums2_index + extra_pop_nums1];
            median_num2 = nums2[nums2_index + extra_pop_nums2];
        }
        else if(nums2_empty){
            median_num1 = nums1[nums1_index + extra_pop_nums1];
            median_num2 = nums1[nums1_index + extra_pop_nums2];
        }
        else{
            if(nums1[nums1_index] < nums2[nums2_index]){
                median_num1 = nums1[nums1_index];
                if(extra_pop_nums2 != 0){
                    if((nums1_index + 1) >= nums1_size){
                        median_num2 = nums2[nums2_index];
                    }
                    else if(nums1[nums1_index+1] < nums2[nums2_index]){
                        median_num2 = nums1[nums1_index + 1];
                    }
                    else{
                        median_num2 = nums2[nums2_index];
                    }
                }
                else{
                    median_num2 = median_num1;
                }
            }
            else{
                median_num1 = nums2[nums2_index];
                if(extra_pop_nums2 != 0){
                    if((nums2_index + 1) >= nums2_size){
                        median_num2 = nums1[nums1_index];
                    }
                    else if(nums1[nums1_index] > nums2[nums2_index+1]){
                        median_num2 = nums2[nums2_index + 1];
                    }
                    else{
                        median_num2 = nums1[nums1_index];
                    }
                }
                else{
                    median_num2 = median_num1;
                }
            }
        }

        return (median_num1 + median_num2)/(double)2.0;
    }
};

int main(){
    Solution solution0;

    vector<int> nums1 = {2, 3, 4};
    vector<int> nums2 = {2, 4, 5};

    double median_num;

    median_num = solution0.findMedianSortedArrays(nums1, nums2);

    cout << "Median Num: " << median_num << endl;
    return 0;
}