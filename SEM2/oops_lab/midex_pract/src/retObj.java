class Test{
    int a;
    Test(int i){
        a = i;
    }
    Test incrbyten(){
        Test temp = new Test(a+10);
        return temp;
    }
}

public class retObj {
    public static void main(String args[]){
        Test ob1 = new Test(2);
        Test ob2;
        ob2 = ob1.incrbyten();
        System.out.println(ob1.a);
        System.out.println(ob2.a);
    }
}
