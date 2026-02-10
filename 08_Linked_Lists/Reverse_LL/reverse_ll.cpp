// LeetCode Problem 206 - https://leetcode.com/problems/reverse-linked-list/description/
// TC - O(n), SC - O(1)

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }


