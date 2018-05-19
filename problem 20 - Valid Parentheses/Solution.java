package leetcode20;

import java.util.Deque;
import java.util.LinkedList;

/**
 * Created by Jon on 5/18/2018.
 */
public class Solution {

    // assume only brackets: ( [ { ) ] }
    public boolean isValid(String s) {
        // go until reaching the last opening bracket
        // create a stack of characters

        if (s.length() % 2 == 1) // odd number of brackets
            return false;

        Character c, lastChar;
        Deque chars = new LinkedList<Character>();

        for (int i = 0; i < s.length(); i++) {
            c = s.charAt(i);
            chars.addLast(c);

            if (chars.size() == 1) { // string starts with closing bracket
                if (c == ')' || c == ']' || c == '}')
                    return false;
            }

            // substring starts with closing bracket
            if (c == ')' || c == ']' || c == '}') {
                // remove the char we just added
                chars.removeLast();

                // compare it to the last char in stack

                if (c == ')') {
                    //System.out.println(chars.getLast() + " " + c);
                    if ((char) chars.getLast() == '(') {

                        // remove the last char from stack, skip one char
                        chars.removeLast();
                        i++;
                        continue;
                    }
                    else return false;
                }
                else if (c == ']') {
                    //System.out.println(chars.getLast() + " " + c);
                    if ((char) chars.getLast() == '[') {
                        // remove the last char from stack, skip one char
                        chars.removeLast();
                        i++;
                        continue;
                    }
                    else return false;
                }
                else { // '}'
                    //System.out.println(chars.getLast() + " " + c);
                    if ((char) chars.getLast() == '{') {
                        // remove the last char from stack, skip one char
                        chars.removeLast();
                        i++;
                        continue;
                    }
                    else return false;
                }
            }

            // is the next bracket a closing bracket?
            if (i+1 < s.length()) { // compare to next char

                c = s.charAt(i + 1);
                if (c == ')' || c == ']' || c == '}') {
                    // check against the last char in the stack

                    // this must be closing bracket for the last opening bracket
                    if (c == ')') {
                        //System.out.println(chars.getLast() + " " + c);
                        if ((char) chars.getLast() == '(') {
                            // remove the last char from stack, skip one char
                            chars.removeLast();
                            i++;
                            continue;
                        }
                        else return false;
                    }
                    else if (c == ']') {
                        //System.out.println(chars.getLast() + " " + c);
                        if ((char) chars.getLast() == '[') {
                            // remove the last char from stack, skip one char
                            chars.removeLast();
                            i++;
                            continue;
                        }
                        else return false;
                    }
                    else { // '}'
                        //System.out.println(chars.getLast() + " " + c);
                        if ((char) chars.getLast() == '{') {
                            // remove the last char from stack, skip one char
                            chars.removeLast();
                            i++;
                            continue;
                        }
                        else return false;
                    }
                }
            }
        }

        return true; // got through test successfully
    }

    public static void main(String[] args) {

        Solution sol = new Solution();

        String s = "()";
        System.out.println(sol.isValid(s));

        s = "()[{}]";
        System.out.println(sol.isValid(s));

        s = "(]";
        System.out.println(sol.isValid(s));

        s = "([)]";
        System.out.println(sol.isValid(s));

        s = "{[]}";
        System.out.println(sol.isValid(s));

    }
}
