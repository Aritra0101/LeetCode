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
 
// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         ListNode* tmp = head;
//         ListNode* ans = new ListNode(0);
//         int count = 0;
//         while(tmp) {
//             count++;
//             tmp=tmp->next;
//         }
//         if(count%2 && count/2 == k-1) return head;

//         ListNode* p1 = head;
//         for(int i=1; i<k; i++) {
//            p1=p1->next;
//         }
//         //cout<<p1->val<<endl;

//         ListNode* p2 = head;
//         for(int i=1; i<=count-k; i++) {
//            p2=p2->next;
//         }
//         //cout<<p2->val<<endl;

//         int temp = p1->val;
//         p1->val = p2->val;
//         p2->val = temp;

//         return head;
//     }
// };

class Solution {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode* p = nullptr;  // Points k-th node from the beginning.
    ListNode* q = nullptr;  // Points k-th node from the end.

    for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
      if (q != nullptr)
        q = q->next;
      if (--k == 0) {
        p = curr;
        q = head;
      }
    }

    swap(p->val, q->val);
    return head;
  }
};
