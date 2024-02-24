# 11286 절댓값 힙

### 문제 핵심

**비교 함수 : cmp**

- cmp(앞에 위치해야 하는 원소, 뒤에 위치해야 하는 원소) = true 가 되어야 함.

- _cmp(a, a)는 반드시 false여야 한다._

- 예를 들어, 절대값 힙에 여러개의 값이 있다면 -1은 그 중에서 우선 순위가 높은 값이므로, cmp(다른 원소, -1) = true가 되어야 한다.

```C++
class cmp{
public:
    bool operator() (int a, int b){
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};
```