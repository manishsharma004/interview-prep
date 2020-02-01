import java.util.*;

public class CalculateGcd {

  private static Integer gcd(Integer first, Integer second) {
    if (first < second) {
      int temp = first;
      first = second;
      second = temp;
    }

    while (second % first != 0) {
      int remainder = second % first;
      second = first;
      first = remainder;
    }

    return first;
  }

  private static Integer gcd_multiple(ArrayList<Integer> numbers) {
    int n = numbers.size();

    if (n < 1) {
      return 0;
    }
    if (n < 2) {
      return numbers.get(0);
    }
    
    Optional<Integer> result = numbers.stream().reduce((a, b) -> gcd(a, b));
    return result.get();
  }

  public static void main(String[] args) {
    System.out.println("Running in JAVA");
    Scanner scanner = new Scanner(System.in);
    int T = Integer.parseInt(scanner.nextLine());

    for (int t=0; t<T; t++) {
      String input_numbers_string = scanner.nextLine();

      String[] numbers_string = input_numbers_string.split(" ");
      ArrayList<Integer> numbers = new ArrayList<>();
      for(int i=0; i<numbers_string.length; i++) {
        numbers.add(Integer.parseInt(numbers_string[i]));
      }

      System.out.println("gcd(" + join_string_list(numbers_string) + ") = "
        + gcd_multiple(numbers));
    }

    scanner.close();
  }

  private static String join_string_list(String[] strings) {
    if (strings.length < 1) {
      return "";
    }
    if (strings.length < 2) {
      return strings[0];
    }
    
    StringBuilder output = new StringBuilder();
    output.append(strings[0]);
    for(int i=1; i<strings.length; i++) {
      output.append(", " + strings[i]);
    }

    return output.toString();
  }
}
