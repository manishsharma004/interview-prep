class Solution {
    public int removeDuplicates(int[] nums) {
        int left = 0;
        int right = 1;

        while (right < nums.length) {
            if (nums[left] != nums[right]) {
                nums[left + 1] = nums[right];
                left++;
            }
            right++;
        }

        return left + 1;
    }
}