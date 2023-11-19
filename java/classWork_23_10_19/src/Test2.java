class Student {
    int age;
    String studentNo;
    String name;
    String sex;
    String major;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getMajor() {
        return major;
    }

    public void setMajor(String major) {
        this.major = major;
    }

    void setAge(int age) {
        this.age = age;
    }

    int getAge() {
        return age;
    }

    void setStudentNo(String studentNo) {
        this.studentNo = studentNo;
    }

    void output() {
        System.out.println("学生的基本信息为：学号" + studentNo + " 姓名" + name + "性别" + sex);
    }
}

class GirlStudent extends Student {
    int shapeCourseGrade;

    void setShapeCourseGrade(int grade) {
        this.shapeCourseGrade = grade;
    }

    int getShapeCourseGrade() {
        return this.shapeCourseGrade;
    }

    void output2() {
        System.out.println(shapeCourseGrade);
    }

    public boolean SetShapeCourseGrade(int i) {
        return false;
    }

    public char[] GetShapeCourseGrade() {
        return null;
    }
}

public class Test2 {
    public static void main(String[] args) {
        GirlStudent stul = new GirlStudent();
        stul.setStudentNo("163001040403");
        stul.setAge(18);
        stul.setName("舒翠芳");
        stul.setSex("女");
        stul.setShapeCourseGrade(90);
        stul.output2();
    }
}
