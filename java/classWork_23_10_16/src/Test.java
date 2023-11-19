class Student {
    private int Age;
    private String StudentNo;

    public boolean SetAge(int value) {
        if (value > 17) {
            Age = value;
            return true;
        } else
            return false;

    }

    public int GetAge() {
        return Age;
    }

    public boolean SetSno(String value) {
        StudentNo = value;
        return true;
    }

    public String GetSno() {
        return StudentNo;
    }
}

class Girlstudent extends Student {
    private int ShapeCourseGrade;

    public boolean SetShapeCourseGrade(int value) {
        if (value >= 0) {
            ShapeCourseGrade = value;
            return true;
        } else
            return false;
    }

    public int GetShapeCourseGrade() {
        return ShapeCourseGrade;
    }
}

public class Test {
    public static void main(String[] args) {
        GirlStudent stu = new GirlStudent();
        boolean ageFlag = stu.SetAge(18);
        boolean gradeFlag = stu.SetShapeCourseGrade(78);
        System.out.println(stu.GetAge());
        if ((ageFlag) && (gradeFlag)) {
            System.out.println(stu.GetAge());
            System.out.println(stu.GetShapeCourseGrade());
        } else {
            System.out.println("error");
        }
    }
}