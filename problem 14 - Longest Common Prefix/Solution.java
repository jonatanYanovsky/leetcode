package leetcode14;

import java.util.List;
import java.util.ArrayList;

/**
 * Created by Jon on 5/18/2018.
 */

public class Solution {

    public static String longestCommonPrefix(List<String> myStrings) {

        String string1, string2, string3;
        string1 = myStrings.get(0);
        string2 = myStrings.get(1);
        string3 = myStrings.get(2);

        int size = Math.min(string1.length(), Math.min(string2.length(), string3.length()));

        char lastChar;
        String ret = "";

        for (int i = 0; i < size; i++) {
            lastChar = string1.charAt(i);

            if (string2.charAt(i) == lastChar && string3.charAt(i) == lastChar)
                ret += lastChar;
            else
                break;
        }

        if (ret.length() == 0)
            return "There is no common prefix among the input strings.";
        else
            return ret;
    }

    public static void main(String[] args) {

        List<String> strings = new ArrayList<>();
        strings.add("flower");
        strings.add("flow");
        strings.add("flight");

        System.out.println("\"" + longestCommonPrefix(strings) + "\"");


        List<String> strings2 = new ArrayList<>();
        strings2.add("dog");
        strings2.add("racecar");
        strings2.add("car");

        System.out.println("\"" + longestCommonPrefix(strings2) + "\"");

    }
}
