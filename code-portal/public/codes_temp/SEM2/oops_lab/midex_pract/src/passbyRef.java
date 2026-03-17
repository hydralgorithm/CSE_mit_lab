class Test{
    int a,b;
    void setVal(int i, int j){
        a = i;
        b = j;
    }
    void TestObject(Test obj){
        obj.a = obj.a + 10;
        obj.b = obj.b -10;
    }
}

public class passbyRef {
    public static void main(String args[]){
        Test ob = new Test();
        ob.setVal(10,20);
        ob.TestObject(ob);
        System.out.println(ob.a+" "+ob.b);
    }
}
