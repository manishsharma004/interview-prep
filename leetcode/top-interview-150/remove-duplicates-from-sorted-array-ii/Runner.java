import java.util.Scanner;

public class Runner {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (scanner.hasNextLine()) {
            String[] numsStr = scanner.nextLine().split(" ");
            int[] nums = new int[numsStr.length];
            for (int i = 0; i < numsStr.length; i++) {
                nums[i] = Integer.parseInt(numsStr[i]);
            }
            
            Solution solution = new Solution();
            int newLength = solution.removeDuplicates(nums);
            
            System.out.println("Array after removing duplicates: ");
            for (int i = 0; i < newLength; i++) {
                System.out.print(nums[i] + " ");
            }
            System.out.println();
        }
        scanner.close();
    }
}
