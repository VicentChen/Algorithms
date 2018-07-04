package com.vicentchen.leetcode;

import java.util.Arrays;

/**
 * Created by Vicent_Chen on 2018/3/29.
 * 16. 3Sum Closest
 * <a>https://leetcode.com/problems/3sum-closest/description/</a>
 */
public class ThreeSumClosest {
    public int threeSumClosest(int[] nums, int target) {

        // avoid surprises
        if (nums == null || nums.length < 3) {
            return 0;
        }

        // sort array
        Arrays.sort(nums);

        // loop
        int length = nums.length;
        int diff = Integer.MAX_VALUE;
        boolean negative = false;
        for (int i = 0; i < length; i++) {

            int l = i + 1, r = length - 1;
            int lastl = l, lastr = r;
            while (l < r) {
                int current = nums[i] + nums[l] + nums[r];
                if (target > current) {
                    if (target - current < diff) {
                        diff = target - current;
                        negative = true;
                    }
                }
                else {
                    if (current - target < diff) {
                        diff = current - target;
                        negative = false;
                    }
                }

                if (current == target) {
                    return target;
                }
                else if (current < target) {
                    lastl = l; lastr = r; l++;
                }
                else {
                    lastl = l; lastr = r; r--;
                }
            }
        }

        return negative ? target - diff : target + diff;
    }

    public static void main(String[] args) {
        ThreeSumClosest threeSumClosest = new ThreeSumClosest();
        int[] nums = {1,2,5,10,11};
        int target = 12;
        System.out.println(threeSumClosest.threeSumClosest(nums, target));
    }
}
