import java.util.*;

public static int postfix(String s) {

        Stack<Integer> st = new Stack<>();

	String[] str = s.split(" ");

        for (String ch : str) {

		try {
			int num = Integer.parseInt(ch);
			st.push(num);
		}
              
		catch (NumberFormatException e) {

               
                        int b = st.pop();
                        int a = st.pop();

                        if (ch.equals("+")) {
                                st.push(a+b);
                        }
                        else if (ch.equals("-")) {
                                st.push(a-b);
                        }
                        else if (ch.equals("*")) {
                                st.push(a*b);
                        }
                        else if (ch.equals("/")) {
                                st.push(a/b);
                        }
                }
        }
        return st.pop();
}
