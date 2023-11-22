var Fraction = /** @class */ (function () {
    function Fraction(f1, f2) {
        this.f1 = f1;
        this.f2 = f2;
    }
    Fraction.prototype.plus = function (fr1) {
        return new Fraction(this.f1 * fr1.f2 + this.f2 * fr1.f1, this.f2 * fr1.f2);
    };
    Fraction.prototype.minus = function (fr1) {
        return new Fraction(this.f1 * fr1.f2 - this.f2 * fr1.f1, this.f2 * fr1.f2);
    };
    Fraction.prototype.multiply = function (fr1) {
        return new Fraction(this.f1 * fr1.f1, this.f2 * fr1.f2);
    };
    Fraction.prototype.division = function (fr1) {
        if (fr1.f1 == 0) {
            console.log("除数不能为0");
            return new Fraction(this.f1, this.f2);
        }
        return new Fraction(this.f1 * fr1.f2, this.f2 * fr1.f1);
    };
    Fraction.prototype.prFrFlo = function (fr) {
        console.log(fr.f1 / fr.f2);
    };
    Fraction.prototype.prFrInt = function (fr) {
        console.log(fr.f1 + "/" + fr.f2);
    };
    Fraction.prototype.Reduction = function (fr) {
        for (var i = 2; i <= (fr.f1 > fr.f2 ? fr.f1 : fr.f2); i++) {
            if (fr.f1 % i == 0 && fr.f2 % i == 0) {
                fr.f1 /= 2;
                fr.f2 /= 2;
                i = 1;
            }
        }
        return fr;
    };
    return Fraction;
}());
var fr = new Fraction(1, 2);
fr = fr.plus(new Fraction(3, 5));
fr.prFrInt(fr);
fr.prFrFlo(fr);
fr = fr.minus(new Fraction(1, 7));
fr.prFrInt(fr);
fr.prFrFlo(fr);
fr = fr.multiply(new Fraction(5, 6));
fr.prFrInt(fr);
fr.prFrFlo(fr);
fr = fr.division(new Fraction(1, 2));
fr.prFrInt(fr);
fr.prFrFlo(fr);
fr = fr.Reduction(fr);
fr.prFrInt(fr);
fr.prFrFlo(fr);
