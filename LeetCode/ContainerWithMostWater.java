package com.vicentchen.leetcode;

/**
 * Created by Vicent_Chen on 2018/3/28.
 * 11. Container With Most Water
 * <a>https://leetcode.com/problems/container-with-most-water/description/</a>
 */
public class ContainerWithMostWater {
    public int maxArea(int[] height) {
        if(height == null || height.length <= 1)
            return 0;
        int length = height.length;
        int capacity = 0;
        int l = 0, r = length - 1;
        while (l < r) {
            capacity = Math.max(capacity, Math.min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return capacity;
    }
}
