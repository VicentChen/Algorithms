package com.vicentchen.leetcode;

/**
 * Created by Vicent_Chen on 2018/3/25.
 * 21. Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 */
class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int val) {
        this.val = val;
    }
}

public class MerageTwoSortedList {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;

        ListNode result = new ListNode(0);
        ListNode head = result;
        while(l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                result.next = l1;
                result = result.next;
                l1 = l1.next;
            }
            else {
                result.next = l2;
                result = result.next;
                l2 = l2.next;
            }
        }

        if (l1 == null) {
            result.next = l2;
        }

        if (l2 == null) {
            result.next = l1;
        }

        return head.next;
    }
}
