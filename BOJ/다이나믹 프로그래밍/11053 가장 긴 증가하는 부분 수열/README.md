# 11053 가장 긴 증가하는 부분 수열

### 문제 핵심
1. 테이블 정의
```cpp
int arr[i]; // i번째 수열의 값
int dp[i];  // i 번째까지 가장 긴 증가하는 부분 수열의 길이
```

2. 점화식
```cpp
if(arr[k] < arr[i]) dp[i] = max(dp[i], dp[k]+1);
```

3. 초기값 정의하기
```cpp
fill(dp, dp+1005, 1); // 1로 초기화해준다. 
```