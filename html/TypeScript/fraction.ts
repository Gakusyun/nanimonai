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
        return new Fraction(this.f1 * fr1.f1, this.f2 * fr1.f2);
    }

    public division(fr1: Fraction) {
        if (fr1.f1 == 0) {
            console.log("除数不能为0");
            return new Fraction(this.f1, this.f2);
        }
        return new Fraction(this.f1 * fr1.f2, this.f2 * fr1.f1);
    }

    public prFrFlo(fr: Fraction) {
        console.log(fr.f1 / fr.f2);
    }

    public prFrInt(fr: Fraction) {
        console.log(fr.f1 + "/" + fr.f2);
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
let fr = new Fraction(1, 2)
fr =fr.plus(new Fraction(3, 5))
fr.prFrInt(fr)
fr.prFrFlo(fr)
fr =fr.minus(new Fraction(1, 7))
fr.prFrInt(fr)
fr.prFrFlo(fr)
fr =fr.multiply(new Fraction(5, 6))
fr.prFrInt(fr)
fr.prFrFlo(fr)
fr =fr.division(new Fraction(1, 2))
fr.prFrInt(fr)
fr.prFrFlo(fr)
fr = fr.Reduction(fr)
fr.prFrInt(fr)
fr.prFrFlo(fr)