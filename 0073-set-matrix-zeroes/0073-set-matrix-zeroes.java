class Solution {
    public void setZeroes(int[][] matrix) {
        int m=matrix.length;
	    int n=matrix[0].length;
	    ArrayList<Integer> a = new ArrayList<>();
	    ArrayList<Integer> b = new ArrayList<>();
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==0){
	                a.add(i);
	                b.add(j);
	            }
	        }
	    }
	    for(int k=0;k<a.size();k++){
            int row = a.get(k);
            for(int j=0;j<n;j++){
                matrix[row][j]=0;
            }
        }
        for(int k=0;k<b.size();k++){
            int col = b.get(k);
            for(int i=0;i<m;i++){
                matrix[i][col]=0;
            }
        }
        
    }
}