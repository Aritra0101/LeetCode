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
private:
    ListNode* reverse(ListNode* head) {
        ListNode* p1 = NULL;
        ListNode* p2 = head;

        while(p2) {
            ListNode* prev = p1;

            p1 = p2;
            p2 = p2->next;

            p1->next = prev;
        }

        return p1;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        int sum = 0, carry = 0;
        ListNode* ptr = head;
        ListNode* prev = NULL;
        while(ptr) {
            sum = (ptr->val * 2) + carry;
            carry = sum / 10;
            ptr->val = sum % 10;

            prev = ptr;
            ptr = ptr->next;
        }

        if(carry) {
            ListNode* node = new ListNode(carry);
            prev->next = node;

        }

        return reverse(head);
    }
};