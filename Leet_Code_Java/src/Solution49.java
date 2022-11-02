import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;

public class Solution49 {
    public static List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<>();
        Map<String, List<String>> dict = new HashMap<>();
        for (String str : strs) {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            if (!dict.isEmpty() && dict.get(sorted) != null) {
                dict.get(sorted).add(str);
            } else {
                dict.put(sorted, new ArrayList<>());
                dict.get(sorted).add(str);
            }
        }
        ans = dict.values().stream().toList();
        return ans;
    }

    public static void main(String[] args) throws IOException {
    String[] strings;
    List<List<String>> ans;
    Path path = Path.of("/home/doodox/Desktop/LeetCode/Leet_Code_Java/" +
            "tests/49tests/" + args[0]);
    String content = Files.readString(path, StandardCharsets.UTF_8);
    content = content.replace("\n", "");
    strings = content.split(" ");
    for (int i = 0; i < strings.length; i++) {
        System.out.print("\"" + strings[i] + "\", ");
    }
        ans = groupAnagrams(strings);
        for (int i = 0; i < ans.size(); i++) {
            System.out.println(ans.get(i));
        }
    }
}
