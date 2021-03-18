/**

*/
// Definition for singly-linked list.

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* node_temp      = head;
        ListNode* node_temp_pre;
        ListNode* node_left      = head;
        ListNode* node_right;

        int index = 1;

        while(index < left){
            node_left             = node_temp;
            node_temp_pre         = node_temp;
            node_temp             = node_temp -> next;
            index ++;
        }

        node_right    = node_temp;
        node_temp_pre = node_temp -> next;

        ListNode* node_swap;

        while((index < right) && (node_temp_pre != NULL)){
            node_swap = node_temp_pre -> next;
            node_temp_pre -> next = node_temp;
            node_temp = node_temp_pre;
            node_temp_pre = node_swap;
            index ++;
        }

        node_left -> next  = node_temp;
        node_right -> next = node_temp_pre;

        if(left == 1){
            head = node_temp;
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

    result = solution0->reverseBetween(head, 1, 1);
    cout << endl << "Result: ";

    temp3 = result;
    while(temp3 != NULL){
        cout << temp3 -> val << ' ';
        temp3 = temp3->next;
    }

    cout << endl;

    return 0;
}