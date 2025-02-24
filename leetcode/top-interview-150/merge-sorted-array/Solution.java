class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int indexM = m-1;
        int indexN = n-1;
        int index = nums1.length - 1;

        while(indexM >= 0 || indexN >= 0) {
            if (indexM >= 0 && indexN >= 0) {
                if (nums1[indexM] < nums2[indexN]) {
                    nums1[index] = nums2[indexN];
                    indexN--;
                } else {
                    nums1[index] = nums1[indexM];
                    indexM--;
                }
            } else if (indexM >= 0) {
                nums1[index] = nums1[indexM];
                indexM--;
            } else if (indexN >= 0) {
                nums1[index] = nums2[indexN];
                indexN--;
            }

            index--;
        }
    }
}