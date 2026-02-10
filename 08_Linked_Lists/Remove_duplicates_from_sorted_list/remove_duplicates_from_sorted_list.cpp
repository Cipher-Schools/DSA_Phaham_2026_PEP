// LeetCode Problem 83 - https://leetcode.com/problems/remove-duplicates-from-sorted-list/     
// TC - O(n), SC - O(1)

ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* curr = head;
        while(curr->next !=NULL){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }