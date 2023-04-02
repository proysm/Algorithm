import java.util.Stack;

class Solution {
    public static Boolean check(String str){

        Stack<Character> S = new Stack<>();

        for(int i=0; i<str.length(); i++){
            if(str.charAt(i) == '(') S.push('(');
            else {
                if(S.empty()) return false;
                S.pop();
            }
        }
        return S.empty();
    }
    public static String solution(String str) {
        String answer = "";
        // 1. 입력이 빈 문자열인 경우, 빈 문자열 반환
        if(str.length() == 0) return answer;

        String u = "", v = "";
        int l=0, r=0;

        // 2. u, v로 분리
        for(int i=0; i<str.length(); i++){
            if(str.charAt(i) == '(') l++;
            else r++;

            if(l==r){ // "균형잡힌 괄호 문자열로" 더 이상 분리할 수 없어야 하기 때문에 반복문 안에 넣는다.
                u = str.substring(0, i+1);
                v = str.substring(i+1);
                break;
            }
        }
        // 3. u가 "올바른 괄호 문자열" 이라면
        if(check(u)){
            answer += u + solution(v);
        }
        // 4. u가 "올바른 괄호 문자열"이 아니라면
        else{
            answer = "(" + solution(v) + ")";
            for(int i=1; i<u.length()-1; i++){
                answer += (u.charAt(i) =='(' ? ')' : '(');
            }
        }
        return answer;
    }

    public static void main(String[] args){
        String s = "()))((()"; // 테스트케이스
        System.out.println(solution(s));
    }
}