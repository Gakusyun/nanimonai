class Student {
    int age;
    String studentNo;
    String name;
    String Class;
    String sex;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    void setAge(int age) {
        this.age = age;
    }

    int getAge() {
        return age;
    }

    void setClass(String Class) {
        this.Class = Class;
    }

    String getclass() {
        return Class;
    }

    void setSex(String sex) {
        this.sex = sex;
    }

    String getSex() {
        return sex;
    }

    void setStudentNo(String studentNo) {
        this.studentNo = studentNo;
    }

    String getStudentNo() {

        return studentNo;
    }
}

class GirlStudent extends Student {
    int shapeCourseGrade;

    void setshapeCourseGrade(int grade) {
        this.shapeCourseGrade = grade;
    }

    int getshapeCourseGrade() {
        return shapeCourseGrade;
    }
}

public class Test {
    public static void main(String[] args) {
        GirlStudent stul = new GirlStudent();
        stul.setStudentNo("163001040403");
        stul.setAge(18);
        stul.setName("舒翠芳");
        stul.setSex("女");
        stul.setshapeCourseGrade(90);
        System.out.println(stul.getName() + " " + stul.getshapeCourseGrade());
    }
}