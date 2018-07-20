/**
 * Created by Vicent_Chen on 2018/3/26.
 *
 * 38. Count and Say
 * <a>https://leetcode.com/problems/count-and-say/description/</a>
 */
public class CountAndSay {
    public String countAndSay(int n) {
        String str = "1";
        for (int i = 1; i < n; i++) {
            String help = "";
            char[] chars = str.toCharArray();
            for (int j = 0; j < chars.length; j++) {
                int count = 1;
                while (j + 1 < chars.length && chars[j+1] == chars[j]) {
                    count++; j++;
                }
                help += "" + count + chars[j];
            }
            str = help;
        }
        return str;
    }
}
