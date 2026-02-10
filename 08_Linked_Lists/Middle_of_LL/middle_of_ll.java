// LeetCode Problem 876 - https://leetcode.com/problems/middle-of-the-linked-list/
// TC - O(n), SC - O(1)

class middle_of_ll {
    public ListNode middleNode(ListNode head) {
        ListNode temp = head;
        int len = 0;

        // Step 1: Calculate length
        while (temp != null) {
            temp = temp.next;
            len++;
        }

        // Step 2: Move to middle
        int mid = len / 2;
        temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp.next;
        }

        return temp;
    }
}
