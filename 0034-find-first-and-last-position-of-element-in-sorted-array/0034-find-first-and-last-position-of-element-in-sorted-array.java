class Solution {
    public int[] searchRange(int[] nums, int target) {
        ArrayList<Integer> a = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            if(nums[i]==target){
                a.add(i);
            }
        }
        int[] arr={-1,-1};
        if(a.size()>0){
            arr[0]=a.get(0);
            arr[1]=a.get(a.size()-1);
        }
        return arr;
    }
}