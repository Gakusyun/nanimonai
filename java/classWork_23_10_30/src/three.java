class Father{
    void speak(){
        System.out.println("I am a father");
    }

    void speak(String s) {
        System.out.println(s);
    }
}

public class three {
    public static void main(String[] args) {
        Father f = new Father();
        f.speak();
        f.speak("Father");
    }
}
