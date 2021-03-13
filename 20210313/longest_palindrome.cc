/*
5. 最长回文子串

给你一个字符串 s，找到 s 中最长的回文子串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring

*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest_palindrome;
        int str_size    = s.size();
        int left_index  = 0;
        int right_index = 0;
        int longest_size = 0;
        
        for(int right_i = 0; right_i < str_size - longest_size/2; right_i++){
            bool palidrome_flag_o = 1;
            bool palidrome_flag_e = 1;
            int  palidrome_step   = 0;
            int  type_flag        = 0;
            while(palidrome_flag_o || palidrome_flag_e){
                if(palidrome_flag_o){ // odd palidrome
                    if((right_i - palidrome_step)>=0 && (right_i + palidrome_step) < str_size){
                        if(s[(right_i - palidrome_step)] == s[(right_i + palidrome_step)]){
                            type_flag = 1;
                        }
                        else{
                            palidrome_flag_o = 0;
                        }
                    }
                    else{
                        palidrome_flag_o = 0;
                    }
                }
                
                if(palidrome_flag_e){ // even palidrome
                    if((right_i - palidrome_step) >= 0 && (right_i + palidrome_step + 1) < str_size){
                        if(s[right_i - palidrome_step] == s[right_i + palidrome_step + 1]){
                            type_flag = 2;
                        }
                        else{
                            palidrome_flag_e = 0;
                        }
                    }
                    else{
                        palidrome_flag_e = 0;
                    }
                }

                if(palidrome_flag_e || palidrome_flag_o){
                    palidrome_step ++;
                }
            }
            palidrome_step --;
            int length_temp;
            if(type_flag == 1){
                 length_temp = 1 + palidrome_step * 2;
                 if(length_temp > longest_size){
                    left_index  = right_i - palidrome_step;
                    right_index = right_i + palidrome_step;
                    longest_size = length_temp;
                 }
            }
            else if(type_flag == 2){
                length_temp = 2 + palidrome_step * 2;
                 if(length_temp > longest_size){
                    left_index  = right_i - palidrome_step;
                    right_index = right_i + palidrome_step + 1;
                    longest_size = length_temp;
                 }
            }
        }
        longest_palindrome = s.substr(left_index, right_index-left_index+1);
        return longest_palindrome;
    }
};

int main(){
    string test_str = "bb";
    string longest_palindrome;
    Solution solution0;

    longest_palindrome = solution0.longestPalindrome(test_str);

    cout << "SRC: " << test_str << endl;
    cout << "TGT: " << longest_palindrome << endl;

    return 0;
}