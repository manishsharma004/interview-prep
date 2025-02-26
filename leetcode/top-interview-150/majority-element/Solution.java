class Solution {
    public int majorityElement(int[] nums) {
        int currentMajority = nums[0];
        int currentVotes = 1;
        for (int i=1; i<nums.length; i++) {
            if (nums[i] != currentMajority) {
                currentVotes--;
            } else {
                currentVotes++;
            }

            if (currentVotes < 1) {
                currentMajority = nums[i];
                currentVotes = 1;
            }
        }

        return currentMajority;
    }
}