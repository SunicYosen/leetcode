/*
83. 删除排序链表中的重复元素

存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。

返回同样按升序排列的结果链表。

示例 1：
输入：head = [1,1,2]
输出：[1,2]

示例 2：
输入：head = [1,1,2,3,3]
输出：[1,2,3]

*/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }

        ListNode* temp = head;

        while(temp->next != NULL){
            if(temp->val == temp -> next -> val){
                temp -> next = temp -> next -> next;
            }
            else{
                temp = temp -> next;
            }
        }

        return head;

    }
};


int main(){
    ListNode *head;

    ListNode *temp1 = new ListNode(0);
    head            = temp1;

    for (int i=1; i<1; i++){
        ListNode *temp = new ListNode();
        temp->val   = i;
        temp1->next = temp;
        temp1       = temp;
    }

    cout << "L: ";
    temp1 = head;
    while(temp1 != NULL){
        cout << temp1->val << ' ';
        temp1 = temp1->next;
    }
    cout << endl;

    ListNode *result;
    ListNode *temp3;

    Solution *solution0 = new Solution();

    result = solution0->deleteDuplicates(head);
    cout << endl << "Result: ";

    temp3 = result;
    while(temp3 != NULL){
        cout << temp3 -> val << ' ';
        temp3 = temp3->next;
    }

    cout << endl;

    return 0;
}