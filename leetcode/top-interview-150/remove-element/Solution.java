class Solution {
    public int removeElement(int[] nums, int val) {
        int lastIndex = 0;

        for(int matchIndex = 0; matchIndex < nums.length; matchIndex++) {
            if (nums[matchIndex] != val) {
                nums[lastIndex] = nums[matchIndex];
                lastIndex++;
            }
        }

        return lastIndex;
    }
}