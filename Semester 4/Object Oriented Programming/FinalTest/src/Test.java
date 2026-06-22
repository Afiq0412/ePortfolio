class One {
    protected int x = 4;

    void setX(int a) {
        x = a;
    }

    protected int getX() {
        return x;
    }
}

class Two extends One {
    protected int x = 8;

    protected int getX() {
        return x;
    }

    public int getB() {
        return x;
    }
}

public class Test {
    public static void main(String[] args) {
        One a = new One();
        One b = new Two();
        Two c = new Two();
        System.out.println(a.getX());
        System.out.println(b.getX());
        System.out.println(c.getB());
        System.out.println(a.x);
        System.out.println(b.x); // explain why? 
        System.out.println(c.x);
    }
}
