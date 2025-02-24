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
            
            if (!scanner.hasNextLine()) break;
            int val = Integer.parseInt(scanner.nextLine());
            
            Solution solution = new Solution();
            int newLength = solution.removeElement(nums, val);
            
            System.out.println("Array after removing element " + val + ": ");
            for (int i = 0; i < newLength; i++) {
                System.out.print(nums[i] + " ");
            }
            System.out.println();
        }
        scanner.close();
    }
}
