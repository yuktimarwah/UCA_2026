import java.util.*;

class Solution {
    public boolean isValid(String s) {
        if (s.length() == 0) {
            return true;
        }
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (ch == '{' || ch == '(' || ch == '[') {
                st.push(ch);
            }
            else {
                if (st.isEmpty()) {
                    return false;
                }
                if (ch == ')' && st.peek() == '(') {
                    st.pop();
                }
                else if (ch == '}' && st.peek() == '{') {
                    st.pop();
                }
                else if (ch == ']' && st.peek() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        if (st.isEmpty()) {
            return true;
        }
        else return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter brackets: ");
        String s = sc.nextLine();

        Solution obj = new Solution();

        if (obj.isValid(s)) {
            System.out.println("Valid");
        } else {
            System.out.println("Invalid");
        }

        sc.close();
    }
}
