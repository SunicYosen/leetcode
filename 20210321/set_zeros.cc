/*
73. 矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

进阶：
一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？
 

示例 1：


输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
示例 2：


输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

提示：

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0 = 1;
        bool row0 = 1;

        for(int i=0; i<matrix.size();i++){
            if(matrix[i][0] == 0){
                col0 = 0;
            }
        }
        for(int i=0; i<matrix[0].size(); i++){
            if(matrix[0][i] == 0){
                row0 = 0;
            } 
        }

        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    if(matrix[0][j] != 0){
                        for(int k=0; k<i; k++){
                            matrix[k][j] = 0;
                        }
                    }
                    if(matrix[i][0] != 0){
                        for(int m=0; m < j; m++){
                            matrix[i][m] = 0;
                        }
                    }
                }
                else{
                    if(matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                    else if(matrix[i][0] == 0){
                            matrix[i][j] = 0;
                    }
                }
            }
        }

        if(col0 == 0){
            for(int i=0; i<matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }
        if(row0 == 0){
            for(int i=0; i<matrix[0].size(); i++){
                matrix[0][i] = 0;
            }
        }
    }
};

int main(){
    vector<vector<int>> test_matrix = {{1,1,1},{1,0,0}};
    cout << "ORG: ";
    for(int i=0; i<test_matrix.size(); i++){
        cout << endl << '\t';
        for(int j=0; j<test_matrix[0].size(); j++){
            cout << test_matrix[i][j] << ' ';
        }
    }

    Solution solution0;

    solution0.setZeroes(test_matrix);

    cout << endl << "RES: ";
    for(int i=0; i<test_matrix.size(); i++){
        cout << endl << '\t';
        for(int j=0; j<test_matrix[0].size(); j++){
            cout << test_matrix[i][j] << ' ';
        }
    }
    cout << endl;
    return 0;
}