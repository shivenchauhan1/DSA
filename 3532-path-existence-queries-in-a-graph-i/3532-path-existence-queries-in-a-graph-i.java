class Solution {
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        boolean[] arr = new boolean[queries.length];

        for (int i = 0; i < queries.length; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            if (l > r) {
                int temp = l;
                l = r;
                r = temp;
            }

            boolean possible = true;

            for (int j = l; j < r; j++) {
                if (nums[j + 1] - nums[j] > maxDiff) {
                    possible = false;
                    break;
                }
            }

            arr[i] = possible;
        }

        return arr;
    }
}