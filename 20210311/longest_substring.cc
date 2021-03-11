/*
3. 无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

示例 4:
输入: s = ""
输出: 0

提示：
0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters

*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length     = s.length();

        int sub_length_max = 1;
        int right_index    = 0;
        int left_index     = 0;
        bool no_same_flag  = 1;

        if (length == 0){
            return 0;
        }

        if (length == 1){
            return 1;
        }

        for (right_index = 1; right_index < length; right_index ++){
            for (int left_index_temp = left_index; left_index_temp < right_index; left_index_temp++){
                if(s[left_index_temp] == s[right_index]){
                    left_index   = left_index_temp + 1;
                    no_same_flag = 0;
                    break;
                }
            }

            if(no_same_flag && ((right_index - left_index + 1) > sub_length_max)){
                sub_length_max = right_index - left_index + 1;
            }

            no_same_flag = 1;
        }

        return sub_length_max;
    }
};

int main(){
    string test_str = "abcabcbb";
    int    length_of_longest_substring;

    Solution solution0;

    length_of_longest_substring = solution0.lengthOfLongestSubstring(test_str);

    cout << "String: " << test_str << endl;
    cout << "Len LS: " << length_of_longest_substring << endl;

    return 0;
}