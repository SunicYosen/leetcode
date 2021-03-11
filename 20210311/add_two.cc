/*
// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

// 请你将两个数相加，并以相同形式返回一个表示和的链表。

// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头

// 示例 1：
// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.

// 示例 2：
// 输入：l1 = [0], l2 = [0]
// 输出：[0]

// 示例 3：
// 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// 输出：[8,9,9,9,0,0,0,1]
//  

// 提示：
// 每个链表中的节点数在范围 [1, 100] 内
// 0 <= Node.val <= 9
// 题目数据保证列表表示的数字不含前导零

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/add-two-numbers
*/

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result;
        ListNode* result_l = new ListNode();
        ListNode* temp1;
        ListNode* temp2;

        temp1 = l1;
        temp2 = l2;

        int forward = 0;

        result = result_l;

        while (temp1 != NULL || temp2 != NULL){
            ListNode *result_temp_node = new ListNode();

            if(temp1 != NULL && temp2 != NULL){
                result_temp_node->val = (temp1 -> val + temp2 -> val + forward) % 10;
                forward               = (int)((temp1 -> val + temp2 -> val + forward) / 10);
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }

            else if(temp1 != NULL){
                result_temp_node->val = (temp1 -> val + forward) % 10;
                forward               = (int)((temp1 -> val + forward) / 10);
                temp1 = temp1 -> next;
            }

            else{
                result_temp_node->val = (temp2 -> val + forward) % 10;
                forward               = (int)((temp2 -> val + forward) /10); 
                temp2 = temp2 -> next;
            }

            result_l -> next = result_temp_node;
            result_l = result_l -> next;
        }

        if(forward != 0){
            ListNode *result_temp_node = new ListNode();
            result_temp_node -> val = forward;
            result_l -> next        = result_temp_node;
        }

        result = result->next;

        return result;
    }
};

int main(){
    ListNode *l1;
    ListNode *l2;

    ListNode *temp1 = new ListNode(0);
    ListNode *temp2 = new ListNode(0);

    l1 = temp1;
    l2 = temp2;

    for (int i=1; i<10; i++){
        ListNode *temp = new ListNode();
        temp->val  = i;
        temp1->next = temp;
        temp1       = temp;
    }

    for (int i=0; i<8; i++){
        ListNode *temp = new ListNode();
        temp->val = 9-i;
        temp2->next = temp;
        temp2       = temp;
    }

    cout << "l1: ";
    temp1 = l1;
    while(temp1 != NULL){
        cout << temp1->val << ' ';
        temp1 = temp1->next;
    }

    temp2 = l2;
    cout << endl << "l2: ";
    while(temp2 != NULL){
        cout << temp2 -> val << ' ';
        temp2 = temp2 -> next;
    }

    cout << endl;

    ListNode *result;
    ListNode *temp3;

    Solution *solution0 = new Solution();

    result = solution0->addTwoNumbers(l1, l2);
    cout << endl << "result: ";

    temp3 = result;
    while(temp3 != NULL){
        cout << temp3 -> val << ' ';
        temp3 = temp3->next;
    }

    cout << endl;

    return 0;
}