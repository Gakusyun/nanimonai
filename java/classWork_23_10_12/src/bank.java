class BankAccount {
    int account_number;
    double leftmoney;

    public double getmoney(double money) {
        if (money > leftmoney) {
            System.out.println("余额不足");
            return 0;
        }
        leftmoney -= money;
        return 1;
    }

    public void savemoney(double money) { // 存款
        leftmoney += money;
    }

    public double getleftmoney() { // 查询余额
        return leftmoney;
    }

    public BankAccount(int number, double money) { // 构造方法，用来初始化变量
        account_number = number;
        leftmoney = money;
    }
}

public class bank {
    public static void main(String[] args) {

        BankAccount ba = new BankAccount(123456, 500);
        ba.savemoney(1000);
        System.out.println("存入1000元后，您的余额为：" + ba.getleftmoney());
        if (ba.getmoney(2000) == 1) {
            System.out.println("取款2000元后，您的余额为：" + ba.getleftmoney());
        }
    }
}
