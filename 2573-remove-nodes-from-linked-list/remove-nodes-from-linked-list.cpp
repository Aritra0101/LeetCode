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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* ptr = head;

        while(ptr != NULL) {
            if(st.empty()) {
                st.push(ptr);
            } else {
                while(!st.empty() && ptr->val > st.top()->val) {
                    st.pop();
                }
                st.push(ptr);
            }

            ptr = ptr->next;
        }

        ListNode* res = new ListNode(st.top()->val);
        st.pop();

        while(!st.empty()) {
            ListNode* node = new ListNode(st.top()->val);
            node->next = res;
            res = node;
            st.pop();
        }

        return res;
    }
};