import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class S1187 {

    public static int makeArrayIncreasing(int[] arr1, int[] arr2) {
        int ans = 0;
        arr2 = Arrays.stream(arr2).sorted().toArray();
        int j = 0;
        for (int i = 1; i < arr1.length; i++) {

        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        for (int argc = 0; argc < args.length; argc++){
            String[] strings;
            Path path = Path.of("/home/doodox/Desktop/LeetCode/Leet_Code_Java/" +
                    "tests/1187tests/" + args[argc]);
            String content = Files.readString(path, StandardCharsets.UTF_8);
            content = content.replace("[", "");
            content = content.replace("]", "");
            List<List<Integer>> arrs = new ArrayList<>();
            int i = 0;
            for (String line : content.split("\n")) {
                arrs.add(new ArrayList<>());
                for (String num : line.split(",")) {
                    arrs.get(i).add(Integer.parseInt(num));
                }
                i++;
            }
            int[] arr1 = new int[arrs.get(0).size()];
            int[] arr2 = new int[arrs.get(1).size()];
            i = 0;
            for (Integer num : arrs.get(0)) {
                arr1[i++] = num;
            }
            i = 0;
            for (Integer num : arrs.get(1)) {
                arr2[i++] = num;
            }
            System.out.println(makeArrayIncreasing(arr1, arr2));
        }
    }
}
