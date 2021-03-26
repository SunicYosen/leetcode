/*
61. 旋转链表
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]

示例 2：
输入：head = [0,1,2], k = 4
输出：[2,0,1]

提示：
链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int link_size  = 0;

        while(temp){
            link_size++;

            if(temp->next == NULL){
                if(link_size > 1 && k % link_size != 0){
                    temp->next = head;
                }
                break;
            }

            temp = temp -> next;
        }

        if(link_size < 2 || k % link_size == 0){
            return head;
        }

        int right_location = link_size - (k % link_size);

        while(right_location > 1){
            head = head -> next;
            cout << head -> val << endl;
            right_location --;
        }

        temp = head;
        head = head -> next;

        temp->next = NULL;

        return head;
    }
};

int main(){
    ListNode *head;

    ListNode *temp1 = new ListNode(0);
    head            = temp1;

    for (int i=1; i<3; i++){
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


    int right_k = 2;

    ListNode *result;
    ListNode *temp3;

    Solution *solution0 = new Solution();

    result = solution0 -> rotateRight(head, right_k);
    cout << endl << "Result: ";

    temp3 = result;
    while(temp3 != NULL){
        cout << temp3 -> val << ' ';
        temp3 = temp3->next;
    }

    cout << endl;

    return 0;
}
