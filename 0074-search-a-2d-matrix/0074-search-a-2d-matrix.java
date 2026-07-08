class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        boolean flag =false;
        int r=matrix.length;
        int c=matrix[0].length;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==target){
                    flag=true;
                }
            }
        }
        return flag;
    }
}