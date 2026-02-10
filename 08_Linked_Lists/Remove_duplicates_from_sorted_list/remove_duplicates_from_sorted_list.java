// LeetCode Problem 83 - https://leetcode.com/problems/remove-duplicates-from-sorted-list/     
// TC - O(n), SC - O(1)

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;

        ListNode curr = head;

        while (curr.next != null) {
            if (curr.val == curr.next.val) {
                // Skip duplicate node
                curr.next = curr.next.next;
            } else {
                curr = curr.next;
            }
        }
        return head;
    }
}