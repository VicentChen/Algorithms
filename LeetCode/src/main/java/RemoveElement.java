/**
 * Created by Vicent_Chen on 2018/3/25.
 *
 * 27. Remove Element
 * Given an array and a value, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
public class RemoveElement {
    public int removeElement(int[] nums, int val) {
        int length = nums.length;
        if (length == 0) return 0;

        int index = 0;
        for (int i = 0; i < length; i++) {
            if (nums[i] != val) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
}
