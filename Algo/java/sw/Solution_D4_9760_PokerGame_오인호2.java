package com.sw;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
 
public class Solution_D4_9760_PokerGame_오인호2 {
    static String[] hand= {"Straight Flush","Four of a Kind","Full House","Flush","Straight","Three of a kind","Two pair","One pair","High card"};
    static boolean isStraight,isFlush,canSF;
    static HashMap<Integer, Integer> numberOfCard;
     
     
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int t = 1; t<=T;t++) {
            String ans = null;
             
            Card[] list = new Card[5];
            for(int i=0;i<5;i++) {
                int num=0;
                String s = sc.next();
                if(s.charAt(1)=='T') {
                    num=10;
                }
                else if(s.charAt(1)=='J') {
                    num=11;
                }
                else if(s.charAt(1)=='Q') {
                    num=12;
                }
                else if(s.charAt(1)=='K') {
                    num=13;
                }
                else if(s.charAt(1)=='A') {
                    num=1;
                }else {
                    num=s.charAt(1)-'0';
                }
                list[i] = new Card(s.charAt(0),num);
            }
            Arrays.sort(list);
            char shape = list[0].shape;
            int num = list[0].num;
            canSF=true;
            isFlush=true;
            isStraight=true;
            numberOfCard = new HashMap<Integer,Integer>();
            numberOfCard.put(num, 1);
            for(int i=1;i<5;i++) {
                if(shape!=list[i].shape) {
                    isFlush=false;
                }
                if(num!=list[i].num-1) {
                    isStraight=false;
                }
                 
                numberOfCard.put(list[i].num, numberOfCard.getOrDefault(list[i].num, 0)+1);
                num = list[i].num;
            }
            num=list[0].num;
            boolean isMountaionStraight=true;
            for(int i=1;i<5;i++) {
                if(num<5) {
                    num+=13;
                }
                if(num!=list[i].num-1) {
                	isMountaionStraight=false;
                    break;
                }
                num=list[i].num-1;
            }
             
            if(isFlush&&isStraight&&(num>4||num==1)) {
                ans = hand[0];
            }else if(numberOfCard.containsValue(4)){
                ans = hand[1];
            }else if(numberOfCard.containsValue(3)&&numberOfCard.containsValue(2)) {
                ans = hand[2];
            }else if(isFlush) {
                ans = hand[3];
            }else if(isStraight||isMountaionStraight) {
                ans = hand[4];
            }else if(numberOfCard.containsValue(3)) {
                ans = hand[5];
            }else if(numberOfCard.containsValue(2)&&numberOfCard.size()==3) {
                ans = hand[6];
            }else if(numberOfCard.containsValue(2)) {
                ans = hand[7];
            }else {
                ans = hand[8];
            }
             
             
            System.out.println("#"+t+" "+ans);
        }
    }
}
 
class Card implements Comparable<Card>{
    char shape;
    int num;
    public Card(char shape, int num) {
        this.shape = shape;
        this.num = num;
    }
     
    @Override
    public int compareTo(Card o) {
        Card c = (Card)o;
        return this.num-c.num;
    }
     
}