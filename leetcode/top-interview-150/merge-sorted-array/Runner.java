import java.util.Scanner;

public class Runner {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String[] nums1Str = scanner.nextLine().split(", ");
        int[] nums1 = new int[nums1Str.length];
        for (int i = 0; i < nums1Str.length; i++) {
            nums1[i] = Integer.parseInt(nums1Str[i]);
        }
        
        int m = scanner.nextInt();
        scanner.nextLine(); // consume the newline
        
        String[] nums2Str = scanner.nextLine().split(", ");
        int[] nums2 = new int[nums2Str.length];
        for (int i = 0; i < nums2Str.length; i++) {
            nums2[i] = Integer.parseInt(nums2Str[i]);
        }
        
        int n = scanner.nextInt();
        
        Solution solution = new Solution();
        solution.merge(nums1, m, nums2, n);
        
        System.out.println("Merged array: ");
        for (int num : nums1) {
            System.out.print(num + " ");
        }
    }
}
