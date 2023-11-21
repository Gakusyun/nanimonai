class Fraction {
    private f1: number
    private f2: number
    constructor(f1: number, f2: number) {
        this.f1 = f1
        this.f2 = f2
    }
    public plus(fr1: Fraction) {
        return new Fraction(this.f1 * fr1.f2 + this.f2 * fr1.f1, this.f2 * fr1.f2);
    }
    public minus(fr1: Fraction) {
        return new Fraction(this.f1 * fr1.f2 - this.f2 * fr1.f1, this.f2 * fr1.f2);
    }

    public multiply(fr1: Fraction) {
        return new Fraction(f1 * fr1.f1, f2 * fr1.f2);
    }

    public division(fr1: Fraction) {
        if (fr1.f1 == 0) {
            System.out.println("除数不能为0");
            return new Fraction(f1, f2);
        }
        return new Fraction(f1 * fr1.f2, f2 * fr1.f1);
    }

    public prFrFlo(fr: Fraction) {
        System.out.println((float) fr.f1 / (float) fr.f2);
    }

    public prFrInt(fr: Fraction) {
        System.out.println(fr.f1 + "/" + fr.f2);
    }

    public Reduction(fr: Fraction) {
        for (let i: number = 2; i <= (fr.f1 > fr.f2 ? fr.f1 : fr.f2); i++) {
            if (fr.f1 % i == 0 && fr.f2 % i == 0) {
                fr.f1 /= 2;
                fr.f2 /= 2;
                i = 1;
            }
        }
        return fr;
    }
}
co