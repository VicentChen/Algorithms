import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by Vicent_Chen on 2018/3/30.
 *
 * 17. Letter Combinations of a Phone Number
 * <a>https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/</a>
 */
public class LetterCombinationsOfAPhoneNumber {
    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.length() == 0)
            return new ArrayList<String>();

        for (char c : digits.toCharArray()) {
            if (c - '0' <= 1)
                return new ArrayList<String>();
        }

        String[] letters = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        LinkedList<String> result = new LinkedList<String>();
        result.add("");

        if (digits.length() == 1) {
            int index = digits.charAt(0) - '0';
            for (char letter : letters[index].toCharArray())
                result.add(letter + "");
            result.remove(0);
            return result;
        }

        LinkedList<String>[] buffers = new LinkedList[100];
        int length = digits.length();
        for (int i = 0; i < length; i++) {
            int index = 0;
            if (i + 1 < length) {
                // compute 2 digit
                int hi = digits.charAt(i) - '0';
                int lo = digits.charAt(i + 1) - '0';
                index = hi * 10 + lo;

                // add list to buffer
                if (buffers[index] == null) {
                    LinkedList<String> twoDigit = new LinkedList<String>();
                    for (char hiChar : letters[hi].toCharArray())
                        for (char loChar : letters[lo].toCharArray())
                            twoDigit.add("" + hiChar + loChar);
                    buffers[index] = twoDigit;
                }

                // add list in buffer
                while (result.peek().length() == i) {
                    String temp = result.remove();
                    for(String str : buffers[index]) {
                        result.add(temp + str);
                    }
                }

                i++; // increase i
            }
            else {
                // compute 1 digit
                index = digits.charAt(i) - '0';
                while (result.peek().length() == i) {
                    String temp = result.remove();
                    for(char c : letters[index].toCharArray()) {
                        result.add(temp + c);
                    }
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        LetterCombinationsOfAPhoneNumber letterCombinationsOfAPhoneNumber = new LetterCombinationsOfAPhoneNumber();
        System.out.println(letterCombinationsOfAPhoneNumber.letterCombinations("232"));
    }
}
