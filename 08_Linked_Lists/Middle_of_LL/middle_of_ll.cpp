// LeetCode Problem 876 - https://leetcode.com/problems/middle-of-the-linked-list/
// TC - O(n), SC - O(1)

ListNode* middleNode(ListNode* head) {
        ListNode*temp = head;
        int len = 0;
        while(temp!= NULL){
            temp = temp->next;
            len++;
        }
        int mid = (len/2);
        temp = head;
        for(int i=0;i<mid;i++){
            temp = temp->next;
        }
        return temp;
}