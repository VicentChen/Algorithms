package com.vicentchen.leetcode;

/**
 * Created by Vicent_Chen on 2018/3/31.
 * 19. Remove Nth Node From End of List
 * <a>https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/</a>
 */

public class RemoveNthNodeFromEndOfList {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // jump protection since always valid

        ListNode realHead = new ListNode(0);
        realHead.next = head;

        ListNode nextToRemove = realHead;
        ListNode end = head; // nextToRemove.next.nextNth = end
        for (int i = 1; i < n; i++) {
            end = end.next;
        }

        while(end.next != null) {
            nextToRemove = nextToRemove.next;
            end = end.next;
        }

        nextToRemove.next = nextToRemove.next.next;

        return realHead.next;
    }
}
