class son {
    int a = 9;

    int getsonValue() {
        return a;
    }

}
public class two {
    public static void main(String[] args) {
        Object o = new son();
        int value = ((son) o).getsonValue();
        System.out.println(value);
    }
}
