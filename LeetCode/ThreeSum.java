package com.vicentchen.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by Vicent_Chen on 2018/3/29.
 * 15. 3Sum
 * <a>https://leetcode.com/problems/3sum/description/</a>
 */
public class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        // result to return
        List<List<Integer>> result = new ArrayList<List<Integer>>();

        // avoid surprises
        if (nums == null || nums.length < 3) {
            return result;
        }

        // sort array
        Arrays.sort(nums);

        // loop
        int length = nums.length;
        for (int i = 0; i < length; i++) {
            int target = -nums[i];
            int l = i + 1, r = length - 1;
            while (l < r) {
                int current = nums[l] + nums[r];
                if (current == target) {
                    result.add(Arrays.asList(nums[l], nums[r], nums[i]));

                    // pass duplicate
                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    l++; r--;
                }
                else if (current < target) {
                    l++;
                }
                else {
                    r--;
                }
            }

            // pass duplicate
            int nexti = i + 1;
            while(nexti < length && nums[nexti] == nums[i])
                nexti++;
            i = nexti - 1;
        }

        return result;
    }

    public static void main(String[] args) {
        int[] nums = {-1,0,1,2,-1,-4};
        ThreeSum threeSum = new ThreeSum();
        System.out.println(threeSum.threeSum(nums));
    }
}
