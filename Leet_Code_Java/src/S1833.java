import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class S1833 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st = null;
    private static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
    private static Integer nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static int maxIceCream(int[] costs, int coins) {
        costs = Arrays.stream(costs).sorted().toArray();
        int total_cost = 0;
        int i = 0;
        for(; i < costs.length; ++i) {
            total_cost += costs[i];
            if (total_cost > coins) {
                break;
            }
        }
        return i;
    }
    public static void main(String[] Args) throws IOException {
        int n = nextInt();
        int[] costs = new int[n];
        for (int i = 0; i < n; ++i) {
            costs[i] = nextInt();
        }
        int coins = nextInt();
        System.out.println(maxIceCream(costs, coins));
    }

}
