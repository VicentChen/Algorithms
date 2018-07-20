/**
 * Created by Vicent_Chen on 2018/3/25.
 *
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 */
public class StrStr {
    public int strStr(String haystack, String needle) {
        int hayLength = haystack.length();
        int neddleLength = needle.length();
        if (neddleLength == 0)
            return 0;
        if (hayLength == 0 || hayLength < neddleLength)
            return -1;

        for (int i = 0; i <= hayLength - neddleLength; i++) {
            if (haystack.substring(i, i + neddleLength).equals(needle)) {
                return i;
            }
        }
        return -1;
    }
}
