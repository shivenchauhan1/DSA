class Solution {
    public int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    public long gcdSum(int[] nums) {
        int max = 0;
        int[] prefixGcd = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            max = Math.max(max, nums[i]);
            prefixGcd[i] = gcd(nums[i], max);
        }
        Arrays.sort(prefixGcd);
        long sum = 0;
        int i = 0;
        int j = prefixGcd.length - 1;
        while(i < j){
            sum += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
}