import java.util.Scanner;
class Merge{
    int[] arr;
    void accept(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        arr = new int[n];
        System.out.println("Enter array element in ascending order without dupolicates: ");
        for(int i=0; i<n; i++){
            int val = sc.nextInt();
            if(i>0 && val<=arr[i-1]){
                System.out.println("Invalid input num should be greater than previous value. Try again!");
                i--;
            } else {
                arr[i] = val;
            }
        }
        sc.close();
    }
    Merge mix(Merge A){
        Merge result = new Merge();
        int[] temp = new int[this.arr.length + A.arr.length];
        int i=0, j=0, k=0;
        while(i<this.arr.length && j<A.arr.length){
            if(this.arr[i]<A.arr[j]){
                temp[k++] = this.arr[i++];
            } else if(this.arr[i] > A.arr[j]){
                temp[k++] = A.arr[j++];
            } else {
                temp[k++] = this.arr[i];
                i++;
                j++;
            }
        }
        while(i<this.arr.length){
            temp[k++] = this.arr[i++];
        }
        while(j<A.arr.length){
            temp[k++] = A.arr[j++];
        }
        result.arr = new int[k];
        for(int id=0; id<k; id++){
            result.arr[id] = temp[id];
        }
        return result;
    }
    void display(){
        for(int n: arr){
            System.out.print(n+" ");
        }
        System.out.println();
    }
}
public class lab3_3fr {
    public static void main(String[] args){
        Merge m1 = new Merge();
        Merge m2 = new Merge();
        m1.accept();
        m2.accept();

        Merge m3 = m1.mix(m2);

        m1.display();
        m2.display();
        m3.display();
    }
}
