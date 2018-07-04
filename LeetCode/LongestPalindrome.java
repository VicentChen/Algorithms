package com.vicentchen.leetcode;

/**
 * Created by Vicent_Chen on 2018/3/27.
 *
 * 5. Longest Palindromic Substring
 * <a>https://leetcode.com/problems/longest-palindromic-substring/description/</a>
 */
public class LongestPalindrome {
    public String longestPalindrome(String s) {
        if (s.length() == 0) return s;

        // pre process
        String help = "$";
        for (int i = 0; i < s.length(); i++) {
            help += '#';
            help += s.charAt(i);
        }
        help += "#^";

        // manacher
        int length = help.length();
        int R = 0, C = 0;
        char[] str = help.toCharArray();
        int[] num = new int[length];
        for (int i = 1; i < length - 1; i++) {
            int iMirror = C - (i - C);
            int distance = R - i;
            if (distance >= 0) {
                if (distance > num[iMirror]) {
                    num[i] = num[iMirror];
                }
                else {
                    num[i] = distance;
                    while(str[i+num[i]+1] == str[i-num[i]-1])
                        num[i]++;
                    C = i;
                    R = i + num[i];
                }
            }
            else {
                num[i] = 0;
                while(str[i+num[i]+1] == str[i-num[i]-1])
                    num[i]++;
                C = i;
                R = i + num[i];
            }
        }

        int max = 0;
        int L = 0;  R = 0;
        for (int i = 1; i < length - 1; i++) {
            if (num[i] > num[max])  max = i;
        }
        return s.substring((max-1-num[max])/2, (max-1+num[max])/2);
    }
}
