class Solution {
    public double findMedianSortedArrays(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int m = arr2.length;
        int[] ans = new int[n + m];
        int i = 0, j = 0, k = 0;
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                ans[k++] = arr1[i++];
            } else {
                ans[k++] = arr2[j++];
            }
        }
        while (i < n) {
            ans[k++] = arr1[i++];
        }
        while (j < m) {
            ans[k++] = arr2[j++];
        }
        double avg=0;
        if(ans.length % 2 == 0){
            avg=(ans[ans.length/2]+ans[(ans.length/2)-1])/2.0;
        }else{
            avg=ans[ans.length/2];
        }
        return avg;
    }
}