import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class S1616 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st = null;

    public static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public static boolean isPalindrom(String s) {
        int i = 0;
        int len = s.length() - 1;
        while (i < len - i) {
            if (s.charAt(i) != s.charAt(len - i)) {
                return false;
            }
            ++i;
        }
        return true;
    }

    public static boolean checkPalindromeFormation(String a, String b) {
        if (isPalindrom(a) || isPalindrom(b)) {
            return true;
        }
        boolean ans = true;
        int i = 0;
        int len = a.length();
        String s;

        while (i < len) {
            s = a.substring(0, i + 1) + b.substring(i + 1, len);
            if (isPalindrom(s)) {
                return true;
            }
            s = b.substring(0, i + 1) + a.substring(i + 1, len);
            if (isPalindrom(s)) {
                return true;
            }
            ++i;
        }
        return false;
    }
    public static void main(String[] Args) throws IOException {
        String a = next();
        String b = next();
        System.out.println(checkPalindromeFormation(a,b));
    }
}
