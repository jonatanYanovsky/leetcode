package leetcode26;

/**
 * Created by Jon on 5/19/2018.
 */
public class Solution {
    public int removeDuplicates(int nums[]) {
        // go through array and remove copies

        if (nums.length == 1)
            return 1;

        int insertIndex = 0;
        int curVal;

        for (int i = 0; i < nums.length; i++) {
            curVal = nums[i];

            if (insertIndex != 0) { // a copy has been deleted
                nums[insertIndex] = curVal;
                insertIndex++;
            }

            if (i+1 < nums.length && curVal == nums[i+1]) { // copies found
                if (insertIndex == 0)
                    insertIndex = i + 1;

                while (i+1 < nums.length && curVal == nums[i + 1])
                    i++;
            }

        }

        return insertIndex;
    }

    public static void main(String[] args) {

        Solution sol = new Solution();

        int[] nums;
        nums = new int[] {0,1,2,3,3,4,4,5,6}; //{1,1,2}; //{0,0,1,1,1,2,2,3,3,4};

        // nums is passed in by reference. (i.e., without making a copy)
        int len = sol.removeDuplicates(nums);

        for (int i = 0; i < len; i++) {
            System.out.print(nums[i] + " ");
        }
    }
}
