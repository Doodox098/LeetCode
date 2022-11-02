import java.util.Scanner;

class Solution338 {
    public static int[] countBits(int n) {
        int[] array = new int[n + 1];
        for (int i = 0; i < array.length; i++) {
            array[i] = countOnes(i);
        }
        return array;
    }
    private static int countOnes(int i) {
        int ans = 0;
        while (i != 0) {
            ans += i & 1;
            i >>= 1;
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner Input = new Scanner(System.in);
        int n = Input.nextInt();
        int[] arr = countBits(n);
        for (int i = 0; i < n + 1; i++) {
            System.out.println(arr[i]);
        }
    }
}
