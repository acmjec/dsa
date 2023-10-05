package CNProblems;

import java.util.Scanner;
import java.util.Stack;

public class BalancedParanthesis {
    public static boolean isBalanced(String expression) {
        if(expression.length()==0){
            return true;
        }
        if(expression.charAt(0)==')'){
            return false;
        }
        Stack<Character> Ans=new Stack<>();
        for(int i=0;i<expression.length();i++){
            if(expression.charAt(i)=='('){
                Ans.push(expression.charAt(i));
            }
            if(expression.charAt(i)==')'){
                if(Ans.peek()=='(' && Ans.size()!=0){
                    Ans.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(Ans.size()==0){
            return true;
        }
        else{
            return false;
        }
        
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        String input=s.nextLine();
        System.out.println(isBalanced(input));
        s.close();
    }
}
