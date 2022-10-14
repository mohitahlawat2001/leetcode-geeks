/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr)
        return nullptr;
        ListNode* first = head , *second = head, *prev=nullptr;
        while(second != nullptr && second->next != nullptr ){
            prev = first;
            first = first->next;
            second = second->next->next;
        }
        prev->next=first->next;
        return head;
    }
};