import java.util.ArrayList;

class student {
    String id;
    String name;

    public student(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String toString() {
        return "学号: " + id + ", 姓名: " + name;
    }
}

public class test {
    public static void main(String[] args) {
        ArrayList<student> theArray = new ArrayList<student>();
        student s;
        s = new student("01", "张一");
        theArray.add(s);
        s = new student("02", "李二");
        theArray.add(s);
        s = new student("03", "王三");
        theArray.add(s);
        s = new student("04", "赵四");
        theArray.add(s);
        for (int i = 0; i < theArray.size(); i++) {
            System.out.print(i + 1);
            System.out.println(theArray.get(i));
        }
        System.out.println("学号为02的学生姓名为：" + theArray.get(1).name);
    }
}