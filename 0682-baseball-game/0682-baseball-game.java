class Solution {
    public int calPoints(String[] operations) {
        Deque<Integer> st = new ArrayDeque<>();
        for (String op : operations) {
            if (op.equals("C")) {
                st.pop();
            } 
            else if (op.equals("D")) {
                st.push(st.peek() * 2);
            } 
            else if (op.equals("+")) {
                int val1 = st.pop();
                int val2 = st.peek();
                st.push(val1);
                st.push(val1 + val2);
            } 
            else {
                st.push(Integer.parseInt(op));
            }
        }
        int sum = 0;
        while (!st.isEmpty()) {
            sum += st.pop();
        }
        return sum;
    }
}