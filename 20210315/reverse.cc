/*
7. 整数反转

给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。

示例 1：
输入：x = 123
输出：321

示例 2：
输入：x = -123
输出：-321

示例 3：
输入：x = 120
输出：21

示例 4：
输入：x = 0
输出：0
 

提示：
-2^31 <= x <= 2^31 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool sign_flag = 0;
        long xtemp;

        if(x > 0){
            sign_flag = 0;
            xtemp  = x;
        }
        else{
            sign_flag = 1;
            xtemp  = -1 * x;
        }
        
        long result = 0;

        cout << xtemp << endl;

        while(xtemp != 0){
            result = result * 10 + xtemp % 10;
            xtemp  = xtemp / 10;
        }

        cout << result << endl;

        if(sign_flag){
            result = -1 * result;
        }

        if((result > 2147483647) || (result < -2147483648)){
            return 0;
        }

        return result;
    }
};

int main(){
    int test_int = -2147483648;
    int reverse;
    Solution solution0;

    reverse = solution0.reverse(test_int);

    cout << "ORG: " << test_int << endl;
    cout << "RES: " << reverse << endl;

    return 0;
}