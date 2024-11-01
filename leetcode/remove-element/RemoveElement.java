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
    public int removeElement(Integer[] nums, Integer val) {
        int currentIndex = 0;
        int uniqueElementIndex = 0;

        while(currentIndex < nums.length) {
            if (nums[currentIndex] != val) {
                nums[uniqueElementIndex] = nums[currentIndex];
                uniqueElementIndex++;
            }

            currentIndex++;
        }
        int uniqueLength = uniqueElementIndex;
        while(uniqueElementIndex < nums.length) {
            nums[uniqueElementIndex++] = 0;
        }

        return uniqueLength;
    }
}
public class RemoveElement {
    
    private static ArrayUtils<Integer> arrayUtils = new ArrayUtils<>();
    private static PrintUtils printUtils = new PrintUtils();

    public static void main(String[] args) {
        var solution = new Solution();
        var nums1 = new Integer[]{3,2,2,3};
        int length = solution.removeElement(nums1, 3);
        printUtils.println("Length: " + length);
        arrayUtils.print("nums1", nums1);
    }
}
