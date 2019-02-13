package com.company;
import java.util.Scanner;

class Typetester {
    private static boolean CheckInt(String s) {
        try {
            Integer.parseInt(s);
        } catch (NumberFormatException e) {
            return false;
        }

        return true;
    }

    public static int SetInt() {
        Scanner sc = new Scanner(System.in);
        String s;
        int x;
        s = sc.nextLine();
        if (CheckInt(s)) {
            x = Integer.parseInt(s);
            return x;
        }
        else{
            System.out.println("Incorrect input!!!");
            System.exit(0);
        }
        return 0;
    }
}
