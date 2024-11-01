class PrintUtils {
    public void print(Object... params) {
        for(Object param: params) {
            System.out.print(param);
        }
    }
    public void println(Object... params) {
        for(Object param: params) {
            System.out.print(param);
        }
        System.out.print("\n");
    }
}

class ArrayUtils<T> {
    private PrintUtils printUtils = new PrintUtils();

    public void print(String name, T[] array) {
        printUtils.print(name + ": ");
        for(T item: array) {
            printUtils.print(item);
            printUtils.print(", ");
        }
        printUtils.println("");
    }
}

class Solution {
    public void merge(Integer[] nums1, Integer m, Integer[] nums2, Integer n) {
        int index1 = m - 1;
        int index2 = n - 1;
        int indexK = m + n - 1;

        while(index1 >= 0 && index2 >= 0) {
            if (nums1[index1] > nums2[index2]) {
                nums1[indexK--] = nums1[index1--];
            } else {
                nums1[indexK--] = nums2[index2--];
            }
        }

        while(index1 >= 0) {
            nums1[indexK--] = nums1[index1--];
        }

        while(index2 >= 0) {
            nums1[indexK--] = nums2[index2--];
        }
    }
}

class MergeSortedArray {
    private static ArrayUtils<Integer> arrayUtils = new ArrayUtils<>();

    public static void main(String[] args) {
        var solution = new Solution();
        var nums1 = new Integer[]{1, 2, 3, 0, 0, 0, 0};
        var nums2 = new Integer[]{2, 5, 6, 8};
        solution.merge(nums1, 3, nums2, nums2.length);

        arrayUtils.print("nums1", nums1);
    }
}