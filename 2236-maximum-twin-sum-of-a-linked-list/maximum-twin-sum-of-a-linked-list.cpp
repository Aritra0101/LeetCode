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
    int pairSum(ListNode* head) {
        int maxi = INT_MIN;
        stack<int> st1, st2;

        ListNode* ptr = head;
        while(ptr != NULL) {
            st1.push( ptr->val );
            ptr = ptr->next;
        }

        int n = st1.size();

        for(int i=1; i<=n/2; i++) {
            st2.push( st1.top() );
            st1.pop();
        }

        while(!st1.empty() && !st2.empty()) {
            maxi = max( maxi, st1.top()+st2.top() );

            st1.pop();
            st2.pop();
        }

        return maxi;
    }
};