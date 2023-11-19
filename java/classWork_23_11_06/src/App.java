class son {
    int s = 9;

    int getsonValue() {
        return s;
    }
}

public class App {
    public static void main(String[] args) {
        Object o = new son();
        int value = ((son) o).getsonValue();
        System.out.println(value);
    }
}