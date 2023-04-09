# 신규 아이디 추천

### 공부한 함수(문자열)
1. 문자열에서 특정 문자를 제거
- erase를 사용해서 제거
    - remove 함수는, 특정 문자가 있는 모든 인덱스를 erase 함수에게 반환하는 역할을 한다.
    - new_id.erase(시작주소, 길이);

2. 문자열에서 특정 문자열을 특정 문자열로 치환
- regex_replace를 사용해서 치환
    - new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());
    - new_id = regex_replace(new_id, regex("[.]+"), ".");

3. 문자인지 확인해주는 함수
- isalpha(문자)

4. 숫자인지 확인해주는 함수
- isdigit(문자)