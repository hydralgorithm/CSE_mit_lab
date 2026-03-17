public class commonEle {
    public static void main(String args[]){
        int[] arr1 = {2,4,6,1,5};
        int[] arr2 = {1,2,7,9,4};
        int n1 = arr1.length;
        int n2 = arr2.length;
        System.out.println("Common ele:");
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(arr2[j-1] == arr1[i-1]){
                    System.out.printf(arr2[j-1]+" ");
                    break;
                }
            }
        }
    }
}
