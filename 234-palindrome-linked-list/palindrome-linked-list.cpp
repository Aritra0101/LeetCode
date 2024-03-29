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
    bool isPalindrome(ListNode* head) {

        string s1 = "";
        string s2 = "";

        while(head!=NULL) {
            s1 += to_string(head->val);

            head  =head->next;
        }   

        s2 = s1;
        reverse(s1.begin(), s1.end());
        if(s1==s2)
            return true;
        return false;     
    }
};