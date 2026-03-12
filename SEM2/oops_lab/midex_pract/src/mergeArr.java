public class mergeArr {
    public static void main(String[] args){
        int[] firstArr = {1,2,3,4,5};
        int[] secondArr = {6,7,8,9,10};
        int n1 = firstArr.length;
        int n2 = secondArr.length;
        int[] mergedArr = new int[n1 + n2]; 
        
        for(int i=0; i<n1; i++){
            mergedArr[i] = firstArr[i];
        }
        for(int i=0; i<n2; i++){
            mergedArr[i+n1] = secondArr[i];
        }

        for(int num: mergedArr){
            System.out.print(num+" ");
        }
    }
}
