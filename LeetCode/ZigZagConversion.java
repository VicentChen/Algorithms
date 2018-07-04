package com.vicentchen.leetcode;

/**
 * Created by Vicent_Chen on 2018/3/27.
 *
 * 6. ZigZag Conversion
 * <a>https://leetcode.com/problems/zigzag-conversion/description/</a>
 */
public class ZigZagConversion {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;
        String[] strings = new String[numRows];
        for (int i = 0; i < numRows; i++) {
            strings[i] = "";
        }
        char[] chars = s.toCharArray();
        int index = 0, step = 1;
        for(char c : chars) {
            strings[index] += c;
            index += step;
            if (index == 0) step = 1;
            if (index == numRows - 1) step = -1;
        }
        String result = "";
        for (int i = 0; i < numRows; i++) {
            result += strings[i];
        }
        return result;
    }
}
