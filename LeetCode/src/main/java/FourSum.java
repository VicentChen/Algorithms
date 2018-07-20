import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by Vicent_Chen on 2018/3/31.
 *
 * 18. 4Sum
 */
public class FourSum {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();

        if (nums == null || nums.length < 4) {
            return result;
        }

        Arrays.sort(nums);

        int length = nums.length;
        int Index_1 = 0, Index_2 = 1, L = 1, R = length - 1;

        for(Index_1 = 0; Index_1 < length - 3; Index_1++) {
            for (Index_2 = Index_1 + 1; Index_2 < length - 2; Index_2++) {
                L = Index_2 + 1; R = length - 1;
                while (L < R) {
                    int current = nums[Index_1] + nums[Index_2] + nums[L] + nums[R];
                    if (current == target) {
                        result.add(Arrays.asList(nums[Index_1], nums[Index_2], nums[L], nums[R]));
                        while (L < R && nums[L] == nums[L + 1]) L++;
                        while (L < R && nums[R] == nums[R - 1]) R--;
                        L++; R--;
                    } else if (current < target) {
                        L++;
                    } else {
                        R--;
                    }
                }
                while (Index_2 < length - 2 && nums[Index_2] == nums[Index_2 + 1]) Index_2++;
            }
            while (Index_1 < length - 3 && nums[Index_1] == nums[Index_1 + 1]) Index_1++;
        }
        return result;
    }

    public static void main(String[] args) {
        FourSum fourSum = new FourSum();
        int[] nums = {-3,-1,0,2,4,5}; int target = 0;
        System.out.println(fourSum.fourSum(nums, target));
    }
}
