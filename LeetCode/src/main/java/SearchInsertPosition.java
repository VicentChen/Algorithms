/**
 * Created by Vicent_Chen on 2018/3/26.
 * 35. Search Insert Position
 * <a>https://leetcode.com/problems/search-insert-position/description/</a>
 */
public class SearchInsertPosition {
    public int searchInsert(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
        int mid = 0;
        if (lo == hi) {
            if (nums[0] >= target) {
                return 0;
            }
            else {
                return 1;
            }
        }

        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        if (lo > mid) {
            if (lo < nums.length && nums[lo] < target) {
                return lo + 1;
            }
            return lo;
        }
        if (hi < mid) {
            if (hi >= 0 && nums[hi] >= target) {
                return hi;
            }
            return mid;
        }
        return 0;
    }
}
