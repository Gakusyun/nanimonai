import java.util.Scanner;

public class tongji {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str = scan.next();
        scan.close();
        int upperCaseLetters = 0;
        int lowerCaseLetters = 0;
        int digits = 0;
        for (char c : str.toCharArray()) {
            if (Character.isUpperCase(c)) {
                upperCaseLetters++;
            } else if (Character.isLowerCase(c)) {
                lowerCaseLetters++;
            } else if (Character.isDigit(c)) {
                digits++;
            }
        }
        System.out.println(upperCaseLetters);
        System.out.println(lowerCaseLetters);
        System.out.println(digits);
    }
}
