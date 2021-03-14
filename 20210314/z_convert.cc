/*
6. Z 字形变换

将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);

示例 1：
输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"

示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I

示例 3：
输入：s = "A", numRows = 1
输出："A"

提示：

1 <= s.length <= 1000
s 由英文字母（小写和大写）、',' 和 '.' 组成
1 <= numRows <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int str_size = s.size();
        string z_convert;
        int cycles = 2 * numRows - 2;

        if (str_size <= 2 | numRows == 1){
            return s;
        }

        for (int row=0; row < numRows; row++){
            int row_position  = row;
            bool between_flag = 0;
            while(row_position < str_size){
                z_convert += s[row_position];
                if(row == 0 || row == numRows-1){
                    row_position += cycles;
                }
                else{
                    if(between_flag){
                        row_position += cycles - 2 * (numRows - row - 1);
                        between_flag  = 0;
                    }
                    else{
                        row_position += 2*(numRows - row - 1);
                        between_flag  = 1;
                    }
                }
            }
        }

        // int first_row_nums   = (str_size + numRows) / (2 * numRows-2);
        // int temp_sub         = (str_size % (2*numRows-2));
        // int second_row_nums;
        // int second_rows;
        // int third_row_nums;
        // int third_rows;
        // int last_row_nums    = (str_size + numRows - 2) / (2 * numRows-2);
        // if(temp_sub == 0){
        //     second_row_nums  = 2 * first_row_nums;
        //     second_rows      = numRows - 2;
        //     third_row_nums  = 2 * first_row_nums;
        //     third_rows      = 0;
        // }
        // else if(temp_sub >= 2 && temp_sub < numRows){
        //     second_row_nums  = 2 * first_row_nums - 1;
        //     second_rows      = temp_sub - 1;
        //     third_row_nums  = 2 * first_row_nums - 2;
        //     third_rows      = numRows - 2 - second_rows;
        // }

        // else if(temp_sub == numRows){
        //     second_row_nums = 2 * first_row_nums - 1;
        //     second_rows      = numRows - 2;
        //     third_row_nums  = 2 * first_row_nums - 1;
        //     third_rows      = 0;
        // }
        // else{
        //     second_row_nums = 2 * first_row_nums - 1;
        //     second_rows     = numRows * 2 - 2 - temp_sub;
        //     third_row_nums  = 2 * first_row_nums;
        //     third_rows      = temp_sub - numRows;
        // }

        // for(int i=1; i < str_size; i++){
        //     int row;
        //     int col;
        //     if(i < first_row_nums)
        // }

        return z_convert;
    }
};

int main(){
    string test_str = "A";
    // "PINALSIGYAHRPI" 
    int num_rows    = 1; 
    string z_convert;
    Solution solution0;

    z_convert = solution0.convert(test_str, num_rows);

    cout << "SRC: " << test_str << endl;
    cout << "TGT: " << z_convert << endl;

    return 0;
}