/*
13. 罗马数字转整数
难度
简单

1239





罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

 

示例 1:

输入: "III"
输出: 3
示例 2:

输入: "IV"
输出: 4
示例 3:

输入: "IX"
输出: 9
示例 4:

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:

输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
 

提示：

1 <= s.length <= 15
s 仅含字符 ('I', 'V', 'X', 'L', 'C', 'D', 'M')
题目数据保证 s 是一个有效的罗马数字，且表示整数在范围 [1, 3999] 内
题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
IL 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。
关于罗马数字的详尽书写规则，可以参考 罗马数字 - Mathematics(https://b2b.partcommunity.com/community/knowledge/zh_CN/detail/10753/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97#knowledge_article)。
*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int str_size = s.size();
        int result   = 0;

        if(str_size == 0){
            return 0;
        }

        int i;
        for(i=0; i < str_size-1; i ++){
            char current_letter = s[i];
            char later_letter   = s[i+1];

            if(current_letter == 'I' && later_letter == 'V'){
                result += 4;
                i ++;
            }
            else if(current_letter == 'I' && later_letter == 'X'){
                result += 9;
                i ++;
            }
            else if(current_letter == 'I'){
                result += 1;
            }
            else if(current_letter == 'V'){
                result += 5;
            }
            else if(current_letter == 'X' && later_letter == 'L'){
                result += 40;
                i++;
            }
            else if(current_letter == 'X' && later_letter == 'C'){
                result += 90;
                i++;
            } 
            else if(current_letter == 'X'){
                result += 10;
            }
            else if(current_letter == 'L'){
                result += 50;
            }
            else if(current_letter == 'C' && later_letter == 'D'){
                result += 400;
                i++;
            }
            else if(current_letter == 'C' && later_letter == 'M'){
                result += 900;
                i++;
            }
            else if(current_letter == 'C'){
                result += 100;
            }
            else if(current_letter == 'D'){
                result += 500;
            }
            else if(current_letter == 'M'){
                result += 1000;
            }
            else{
                continue;
            }
        }

        if(i < str_size){
            switch(s[str_size-1]){
                case 'I': result += 1; break;
                case 'V': result += 5; break;
                case 'X': result += 10; break;
                case 'L': result += 50; break;
                case 'C': result += 100; break;
                case 'D': result += 500; break;
                case 'M': result += 1000; break;
                default: break;
            }
        }
        return result;

    }
};

int main(){
    string test_str = "MCMXCIV";
    Solution solution0;

    int result = solution0.romanToInt(test_str);

    cout << "RMN: " << test_str << endl;
    cout << "INT: " << result << endl;

    return 0;
}