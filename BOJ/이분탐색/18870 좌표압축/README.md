# 18870 좌표압축

### 문제 이해
중복을 제외하고 나보다 작은 수가 몇 개 있는지를 출력하는 문제.

### 새롭게 알게 된 점

```C++
lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin();
```
lower_boud / upper_bound 는 iterator를 반환하기 때문에 index를 알기 위해서는 uni.begin()을 빼주는 작업이 필요하다.
