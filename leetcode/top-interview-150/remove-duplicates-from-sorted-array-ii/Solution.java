class Solution {
    public int removeDuplicates(int[] nums) {
        int COUNTER_RESET_VALUE = 1;
        int left = 0;
        int right = 1;
        int duplicateCounter = COUNTER_RESET_VALUE;

        while(right < nums.length) {
            if (nums[left] != nums[right]) {
                nums[left+1] = nums[right];
                left++;
                duplicateCounter = COUNTER_RESET_VALUE;
            } else if (duplicateCounter > 0) {
                nums[left+1] = nums[right];
                left++;
                duplicateCounter--;
            }
            right++;
        }

        return left + 1;
    }
}