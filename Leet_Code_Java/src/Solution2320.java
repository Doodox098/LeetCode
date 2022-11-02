import java.math.BigInteger;

public class Solution2320 {
    public static int countHousePlacements(int n) {
        Integer sum = 1;
        Integer num_zeros = 1;
        Integer old_sum;
        for (int i = 0; i < n; i++) {
            old_sum = sum;
            sum += num_zeros;
            num_zeros = old_sum;
            if (sum > 1000000007) {
                sum %= 1000000007;
                num_zeros %= 1000000007;
            }
        }
        sum = (((BigInteger.valueOf(sum)).multiply(BigInteger.valueOf(sum))).mod(BigInteger.valueOf(1000000000 + 7))).intValue();
        int ans = ((int) sum);
        return ans;
    }
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int ans = Solution2320.countHousePlacements(n);
        System.out.println(ans);
    }
}
