import java.util.Scanner;

class ComputeDemo {

    // checks if a number is armstrong
    static boolean computeArmstrong(int n) {
        int temp = n;
        int digits = String.valueOf(n).length(); // count how many digits
        int sum = 0;

        while (temp != 0) {
            int d = temp % 10;
            sum += Math.pow(d, digits); // d to the power of number of digits
            temp = temp / 10;
        }

        return sum == n; // true if armstrong, false if not
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter lower limit: ");
        int lower = sc.nextInt();
        System.out.print("Enter upper limit: ");
        int upper = sc.nextInt();

        int totalSum = 0;

        System.out.println("Armstrong numbers between " + lower + " and " + upper + ":");
        for (int i = lower; i <= upper; i++) {
            if (computeArmstrong(i)) {
                System.out.println(i);
                totalSum += i;
            }
        }

        System.out.println("Sum of Armstrong numbers: " + totalSum);
    }
}