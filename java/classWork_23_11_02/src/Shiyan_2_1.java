class People {
    public void say() {
        System.out.println("Say from People");
    }
}

class Teacher extends People {
    public void say() {
        System.out.println("Say from Teacher");
    }
}

class Student extends People {
    public void say() {
        System.out.println("Say from Student");
    }
}

class Shiyan_2_1 {
    public static void main(String[] args) {
        Teacher t = new Teacher();
        People s = t;
        s.say();
    }
}
