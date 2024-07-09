# 15686 치킨 배달

### 이용한 STL 함수
- abs() : 절대값 함수
- next_premutation : 조합 함수

```c++
// 조합
int a[4] = {0, 0, 1, 1};
do{
	for(int i=0; i<4; i++){
		if(a[i] == 0) cout << i+1; // 0이 위치한 인덱스 값 출력 1~4
	}
	cout << "\n";
	
}while(next_permutation(a, a+4));
/*
12
13
14
23
24
34
*/
```