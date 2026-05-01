package SEM2.oops_lab.endsemfin;
class A{
    public void printt(){
        System.out.println("Class A print method");
    }
}
class B extends A{
    public void printt(){
        System.out.println("Class B print method");
    }
}
class C extends A{
    public void printt(){
        System.out.println("Class C print method");
    }
}
class D extends A{
    public void printt(){
        System.out.println("Class D print method");
    }
} 
public class fin7 {
    public static void main(String[] args){
        D obj = new D();
        obj.printt();
        A obj2 = new C();
        obj2.printt();
    }
}
