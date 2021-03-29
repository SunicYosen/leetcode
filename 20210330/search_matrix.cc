/*
74. 搜索二维矩阵

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

示例 1：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true

示例 2：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false


提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int  col_index = 0;
            int  row_index = 0;

            while(row_index < matrix.size()){
                if(matrix[row_index][0] > target){
                    break;
                }
                row_index ++;
            }

            if(row_index == 0){
                return false;
            }

            row_index --;

            while(col_index < matrix[0].size()){
                if(matrix[row_index][col_index] > target){
                    break;
                }
                col_index ++;
            }

            col_index --;

            if(matrix[row_index][col_index] == target){
                return true;
            }
            else{
                return false;
            }
    }
};

int main(){
    vector<vector<int>> test_matrix = {{1}};
    int target = 3;

    Solution solution0;

    bool result = solution0.searchMatrix(test_matrix, target);

    cout << result << endl;

    return 0;
}