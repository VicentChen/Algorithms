package com.vicentchen.leetcode;

/**
 * Created by Vicent_Chen on 2018/3/27.
 * 12. Integer to Roman
 *
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * <b>STUPID ANSWER</b>
 */
public class IntegerToRoman {
    String help(int count, String lo, String half, String hi) {
        switch (count) {
            case 1: return lo;
            case 2: return lo + lo;
            case 3: return lo + lo + lo;
            case 4: return lo + half;
            case 5: return half;
            case 6: return half + lo;
            case 7: return half + lo + lo;
            case 8: return half + lo + lo + lo;
            case 9: return lo + hi;
            default:return "";
        }
    }

    public String intToRoman(int num) {
        int thousand = num / 1000;
        num %= 1000;
        int hundred = num / 100;
        num %= 100;
        int ten = num / 10;
        num %= 10;
        int one = num;

        String result = "";
        for (int i = 0; i < thousand; i++) {
            result += 'M';
        }
        result += help(hundred, "C", "D", "M");
        result += help(ten    , "X", "L", "C");
        result += help(one    , "I", "V", "X");
        return result;
    }
}
