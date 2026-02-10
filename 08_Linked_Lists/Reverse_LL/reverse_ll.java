class reverse_ll {
    public ListNode reverseList(ListNode head) {
        ListNode curr = head;
        ListNode prev = null;
        ListNode next = null;

        while (curr != null) {
            next = curr.next;   // store next node
            curr.next = prev;   // reverse pointer
            prev = curr;        // move prev forward
            curr = next;        // move curr forward
        }

        return prev;  // new head
    }
}
