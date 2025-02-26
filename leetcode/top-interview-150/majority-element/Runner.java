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
            int majorityElement = solution.majorityElement(nums);
            
            System.out.println("Majority element: " + majorityElement);
        }
        scanner.close();
    }
}
