package com.vicentchen.leetcode;

/**
 * Created by Vicent_Chen on 2018/3/28.
 *
 * 8. String to Integer (atoi)
 * <a>https://leetcode.com/problems/string-to-integer-atoi/description/</a>
 */
public class AToI {
    public int myAtoi(String str) {
        if (str == null) return 0;
        int len = str.length();

        int result = 0;
        int limit = -Integer.MAX_VALUE;
        int multmin;
        boolean negative = false;
        int i = 0;
        int digit;
        if (len > 0) {
            while (str.charAt(i) == ' ')
                i++;
            char firstChar = str.charAt(i);
            if (firstChar < '0') {
                if (firstChar == '-') {
                    negative = true;
                    limit = Integer.MIN_VALUE;
                }
                else if (firstChar != '+') {
                    return 0;
                }
                i++;
            }

            multmin = limit / 10;

            while(i < len) {
                digit = str.charAt(i++) - '0';
                if (digit < 0 || digit >= 10) {
                    return negative ? result : -result;
                }
                if (result < multmin) {
                    return negative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
                }
                result *= 10;
                if (result < limit + digit) {
                    return negative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
                }
                result -= digit;
            }

        }
        else {
            return 0;
        }

        return negative ? result : -result;
    }
}
