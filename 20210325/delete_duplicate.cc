/*
82. 删除排序链表中的重复元素 II
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:
输入: 1->2->3->3->4->4->5
输出: 1->2->5

示例 2:
输入: 1->1->1->2->3
输出: 2->3
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
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* head_temp = new ListNode();
        head_temp -> next   = 0;

        ListNode* temp      = head_temp;

        while(temp->next != NULL && temp->next->next != NULL){
            if(temp->next->val == temp->next->next->val){
                int value = temp->next->val;
                while(temp -> next && temp -> next -> val == value){
                    temp -> next = temp -> next -> next;
                }
            }
            else{
                temp = temp -> next;
            }
        }
        return head_temp->next;
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