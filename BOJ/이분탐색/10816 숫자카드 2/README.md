# 10816 수 찾기 2

### 문제 핵심
```
target이 존재하는 처음 위치 (lower_idx)와
target이 마지막으로 존재하는 위치 + 1 (upper_idx) 
을 빼주면된다.

STL에서 제공하는 
lower_boud(시작, 종료, target) 
upper_bound(시작, 종료, target)
을 사용하도 된다.
```

### 주의할 점
1. 배열을 정렬한다.
2. 무한 루프에 빠지지 않게 mid 값을 정한다.
