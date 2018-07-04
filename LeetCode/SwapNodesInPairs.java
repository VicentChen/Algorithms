package com.vicentchen.leetcode;

/**
 * Created by Vicent_Chen on 2018/4/1.
 * 24. Swap Nodes in Pairs
 * <a>https://leetcode.com/problems/swap-nodes-in-pairs/description/</a>
 */
public class SwapNodesInPairs {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null)
            return head;

        // first swap
        ListNode curr = head;
        ListNode next = curr.next;
        curr.next = next.next;
        next.next = curr;
        ListNode result = next;

        while(curr != null) {
            ListNode prev = curr;
            curr = curr.next;
            if (curr != null) next = curr.next;
            else break;
            if (next == null) break;

            curr.next = next.next;
            next.next = curr;
            prev.next = next;
        }

        return result;
    }
}
