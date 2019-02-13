package com.company;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import static java.lang.StrictMath.sqrt;

////////////////////////////////////////////////////////////////////////////
// Задача: Из списка финишировавших спортсменов определить, дошёл ли до
//          финиша спортсмен с определённым номером. Поиск спортсмена
//          реализовать с помощью следующих видов поиска: поиск перебором,
//          поиск с преградой, инарный поиск.
//
////////////////////////////////////////////////////////////////////////////
public class Main {
    public static void main(String[] args) {
        int n, x;
        int Brute_Compares, Barricade_Compares, Binary_Compares;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length of array");
        n = Typetester.SetInt();
        List<Integer> list = new ArrayList();
        for(int i = 0; i < n; i++){
            System.out.println("Enter element " + i + " of array ");
            list.add(Typetester.SetInt());
        }
        System.out.println("Enter your element:" );
        x = Typetester.SetInt();
        System.out.println("1. Brute Force Search Result: " );
        Brute_Compares = Brute_Force_Search(list, n, x);
        System.out.println("2. Barricade Search Result: " );
        Barricade_Compares = Barricade_Search(list, n, x);
        if(Brute_Compares > Barricade_Compares){ System.out.println("3. Barricade Search is more effective"); }
        else if(Brute_Compares < Barricade_Compares){ System.out.println("3. Brute Force Search is more effective"); }
        else {System.out.println("3. Searches are same effective");}
        System.out.println("4. Binary Search Result: " );
        Binary_Compares = Binary_Search(list, x);
        System.out.println("5. Binary Search Result(Gold Cut): " );
        Binary_Search_Gold_Cut(list, x);
        if (Binary_Compares < Brute_Compares && Binary_Compares < Barricade_Compares){ System.out.println("6. Binary Search is more effective"); }
        else if (Brute_Compares < Barricade_Compares && Brute_Compares < Binary_Compares){ System.out.println("6. Brute force search is more effective"); }
        else if (Barricade_Compares < Brute_Compares && Barricade_Compares < Binary_Compares){ System.out.println("6. Barricade search is more effective"); }
        else {System.out.println("6. There is no only most effective search");}
    }

    public static int Brute_Force_Search(List<Integer> myList, int l, int x){
        int k = 0;
        int compared = 0;
        while(k != l && myList.get(k) != x){
            k++;
            compared++;
        }
        if (k == l) { System.out.println("No x in Array"); }
        else { System.out.println("Array consists of x. Index: " + k); }
        return compared;
    }

    public static int Barricade_Search(List<Integer> myList, int l, int x){
        int k = 0;
        int compared = 0;
        myList.add(x);
        while(myList.get(k) != x){
            k++;
            compared++;
        }
        if (k == l){
            System.out.println("No x in Array");
        } else{
            System.out.println("Array consists of x. Index: " + k);
        }
        return compared;
    }

    public static int Binary_Search(List<Integer> myList, int x){
        myList = Bubble_Sort_Array(myList);
        int l = 0;
        int r = myList.size() - 1;
        int k = 0;
        int compared = 0;
        boolean isFound = false;
        while((l < r) && (!isFound)){
            int m = (r - l) / 2;
            if(myList.get(m) == x){
                isFound = true;
                k = m;
            }
            else if(myList.get(m) < x) { r = m; }
            else { l = m; }
            compared++;
        }
        if (isFound && k != 0){ System.out.println("Array consists of x. Index: " + (k - 1)); }
        else{ System.out.println("No x in Array"); }
        return compared;
    }

    public static List<Integer> Bubble_Sort_Array(List<Integer> myList){
        for(int i = 0; i < myList.size() - 1; i++){
            for(int j = i + 1; j < myList.size(); j++){
                if(myList.get(i) >  myList.get(j)){
                    int t = myList.get(i);
                    myList.set(i, myList.get(j));
                    myList.set(j, t);
                }
            }
        }
        return myList;
    }

    public static void Binary_Search_Gold_Cut(List<Integer> myList, int x){
        myList = Bubble_Sort_Array(myList);
        int l = 0;
        int r = myList.size() - 1;
        int k = 0;
        boolean isFound = false;
        while((l < r) && (!isFound)){
            int m = (int)Math.round((r - l) * (3 - sqrt(5)) / 2);
            if(myList.get(m) == x){
                isFound = true;
                k = m;
            }
            else if(myList.get(m) < x) { r = m; }
            else { l = m; }

        }
        if (isFound && k != 0){ System.out.println("Array consists of x. Index: " + k); }
        else{ System.out.println("No x in Array"); }
    }
}
