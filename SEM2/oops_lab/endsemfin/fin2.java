package SEM2.oops_lab.endsemfin;

public class fin2 {
    public static void main(String[] args){
        int num = Integer.parseInt(args[0]);
        int temp = num;
        int count = 0;
        while(temp != 0){
            count++;
            temp /= 10;
        }

        int[] arr = new int[count];
        temp = num;
        for(int i = count-1; i>=0; i--){
            arr[i] = temp%10;
            temp /= 10;
        }
        int ctr;
        for(int i=0; i<count; i++){
            ctr = 0;
            for(int j=0; j<count; j++){
                if(i!=j){
                    if(arr[i]==arr[j]){
                        ctr++;
                    }
                }
            }
            if(ctr == 0)
                System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}
