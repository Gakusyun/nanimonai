package yuanshen;
public class Student {
    int id;
    String name;

    public Student() {
    }

    public Student(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public void study() {
        System.out.println("Student is studing");
    }
}