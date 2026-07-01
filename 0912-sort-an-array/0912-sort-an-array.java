class Solution {
    public int[] sortArray(int[] nums) {
        mergeSort(nums, 0, nums.length - 1);
        return nums;
    }

    private void mergeSort(int[] nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }

    private void merge(int[] nums, int left, int mid, int right) {

        int n1 = mid - left + 1;
        int n2 = right - mid;

        int[] L = new int[n1];
        int[] R = new int[n2];

        // Copy left half
        for (int i = 0; i < n1; i++) {
            L[i] = nums[left + i];
        }

        // Copy right half
        for (int j = 0; j < n2; j++) {
            R[j] = nums[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;

        // Merge the two sorted arrays
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                nums[k] = L[i];
                i++;
            } else {
                nums[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements from L
        while (i < n1) {
            nums[k] = L[i];
            i++;
            k++;
        }

        // Copy remaining elements from R
        while (j < n2) {
            nums[k] = R[j];
            j++;
            k++;
        }
    }
}