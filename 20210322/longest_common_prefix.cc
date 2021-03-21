/*
14. 最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
 

提示：

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result    = "";

        if(strs.size() == 0){
            return "";
        }

        int shortest_len = strs[0].size();

        for(int i=0; i < strs.size(); i++){
            if(shortest_len > strs[i].size()){
                shortest_len = strs[i].size();
            }
        }

        if (shortest_len == 0){
            return "";
        }

        for(int i=0; i < shortest_len; i++){
            for(int j=1; j < strs.size(); j++){
                if(strs[j][i] != strs[0][i]){
                    return result;
                }
            }
            result += strs[0][i];
        }
        return result;
    }
};

int main(){
    vector<string> test_str = {"dog","dog","dog"};

    Solution solution0;

    string result = solution0.longestCommonPrefix(test_str);

    cout << result << endl;

    return 0;
}