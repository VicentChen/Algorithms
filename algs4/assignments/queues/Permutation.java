import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdRandom;

/**
 * Created by Vicent_Chen on 2018/7/25.
 */
public class Permutation {
    public static void main(String[] args) {
        RandomizedQueue<String> queue = new RandomizedQueue<String>();

        int count = 0;
        int k = Integer.parseInt(args[0]);

        while (!StdIn.isEmpty()) {
            queue.enqueue(StdIn.readString());
        }

        for (String s : queue) {
            if (k == 0) break;
            System.out.println(s);
            k--;
        }
    }
}
