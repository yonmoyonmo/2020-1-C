#include <stdio.h>
#define TRUE 1
#define FALSE 0

int isPrime(int n); //차례대로 설명하기 위해서 함수들을 전방선언함.
int primeFactorize(int* primes, int n);
static int primeArrCounter = 0; //유의미한 값(소인수들)의 저장을 카운팅 할 변수.

int main(void) {
	int n;//이곳에 입력받을 것임.
	int primefactors[200];//소인수들을 담을 배열, 소인수분해 함수 내부에서 소인수들을 저장할 때 사용함.
							//함수 내부에서 재귀적으로 소인수를 출력하기 때문에 딱히 소인수들을 모아놓을 이유가 없지만
							//배열과제에 배열이 없으면 허전하기 때문에 넣음.
	int i = 0;
	for (i = 0; i < 200; i++) {//배열초기화해줌
		primefactors[i] = 0;
	}

	printf("정수 입력: "); 
	scanf_s("%d", &n);//입력 받음
	if (isPrime(n)==TRUE) { //입력받은 수가 소수인지 확인
		printf("소수입니다.\n");
		system("PAUSE");
		return 0;// 소수면 끝임.
	}
	printf("%d=", n);
	primeFactorize(primefactors, n);//소인수분해 함수, 재귀적으로 소인수를 구함(가산점)
	//배열과 입력받은 합성수를 넘겨 주면 배열에 그 합성수의 소인수를 채워준다.
	printf("\n");
	system("PAUSE");
	return 0;
}

int isPrime(int n) { //소수인지 아닌지 판단하는 함수
	int i = 0; //2부터 n-1까지의 정수로 n을 나눴을 때 딱 떨어지는 수가 있다면 n은 소수가 아님.
	int x = 0;
	for (i = 2; i < n; i++) {
		x = n % i;
		if (x == 0) return FALSE;
	}
	return TRUE;
}

int primeFactorize(int* primes, int n) { //소인수분해 함수
	if (isPrime(n) == TRUE) {
		primes[primeArrCounter] = n;
		primeArrCounter++;
		printf("*%d", n);
		return TRUE;
	}//->탈출조건: n이 소수일 경우

	int p = 0;
	for (p = 2; p < n; p++) {
		if (isPrime(p) == TRUE) {				//소수가 아니라면 쓰지 않음.
			if (n % p == 0) {					//p로 나눌 때 나머지가 없어야 함.
				n = n / p;						//n을 p로 나눈 몫을 다시 n에 넣고
				primes[primeArrCounter] = p;	//소인수배열에 소인수를 넣음
				primeArrCounter++;				//소인수가 추가될 때마다 잘 세어줌.
				if (primeArrCounter == 1) {		//예제와 같이 출력하기 위해서
					printf("%d", p);			//처음 소인수는 *을 출력하지 않게 해줌.
				}
				else {
					printf("*%d", p);
				}
				return primeFactorize(primes, n);//p로 나눠진 n을 이용해 다시 재귀호출함.
			}
		}
	}
	return FALSE;
}