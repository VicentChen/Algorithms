package com.vicentchen.leetcode;

/**
 * Created by Vicent_Chen on 2018/3/24.
 * Leetcode 13. Roman to Integer
 * <a>https://leetcode.com/problems/roman-to-integer/description/</a>
 */
public class RomanToInteger {
    public int romanToInt(String s) {
        int strLength = s.length();
        if (strLength == 0) {
            return 0;
        }
        int result = 0;
        int temp = 0;
        char[] chars = s.toCharArray();
        int i;
        for (i = 0; i < strLength - 1; i++) {
            temp = 0;
            switch (chars[i]) {
                case 'I':
                    temp += 1;
                    switch (chars[i+1]) {
                        case 'X':
                        case 'C':
                        case 'M':
                        case 'V':
                        case 'L':
                        case 'D': temp *= -1; break;
                        default: break;
                    }
                    break;
                case 'X':
                    temp += 10;
                    switch (chars[i+1]) {
                        case 'C':
                        case 'M':
                        case 'L':
                        case 'D': temp *= -1; break;
                        default: break;
                    }
                    break;
                case 'C':
                    temp += 100;
                    switch (chars[i+1]) {
                        case 'M':
                        case 'D': temp *= -1; break;
                        default: break;
                    }
                    break;
                case 'M': temp += 1000; break;
                case 'V': temp += 5; break;
                case 'L': temp += 50; break;
                case 'D': temp += 500; break;
                default: temp += 0; break;
            }
            result += temp;
        }
        switch (chars[i]) {
            case 'I': result += 1; break;
            case 'X': result += 10; break;
            case 'C': result += 100; break;
            case 'M': result += 1000; break;
            case 'V': result += 5; break;
            case 'L': result += 50; break;
            case 'D': result += 500; break;
            default: result += 0; break;
        }
        return result;
    }
}
