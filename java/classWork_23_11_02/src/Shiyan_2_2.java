interface People {
    void say();
}

class Student implements People {
    public void say() {
        System.out.println("Student");
    }
}

class Teacher implements People {
    public void say() {
        System.out.println("Teacher");
    }
}

class Shiyan_2_2 {
    public static void main(String[] args) {
        People p = new Student();
        p.say();
    }
}
