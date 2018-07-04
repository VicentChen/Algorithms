package com.vicentchen.leetcode;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by Vicent_Chen on 2018/3/25.
 * 14. Longest Common Prefix
 * <a>https://leetcode.com/problems/longest-common-prefix/description/</a>
 */
public class LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        int length = strs.length;
        if (length == 0 || strs[0].length() == 0) {
            return "";
        }

        // first pass: find shortest and check 1st char
        char base = strs[0].charAt(0);
        int shortestIndex = 0;
        int shortestLength = strs[0].length();
        for (int i = 0; i < length; i++) {
            // jump 0
            if (strs[i].length() == 0) {
                return "";
            }
            // check 1st char
            if (base != strs[i].charAt(0)) {
                return "";
            }
            // find shorts
            if (shortestLength > strs[i].length()) {
                shortestIndex = i;
                shortestLength = strs[i].length();
            }
        }

        // second pass: check chars left in shortest str
        for (int j = 1; j < shortestLength; j++) {
            base  = strs[shortestIndex].charAt(j);
            for (int i = 0; i < length; i++) {
                if (base != strs[i].charAt(j)) {
                    return strs[shortestIndex].substring(0, j);
                }
            }
        }
        return strs[shortestIndex];
    }
}
