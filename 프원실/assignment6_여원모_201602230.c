#include <stdio.h>
#define ARRLENGTH 10 //배열의 길이를 고칠 때를 대비해서 define 했다.


//함수에 대한 주석은 함수 정의에서...
void fillarr(int* arr);
void printarr(int* arr);
void fillparrWitharr(int** parr, int* arr);
void printparr(int** parr);
void sortparr(int** parr);

int main(void) {
	int arr[ARRLENGTH]; //10개의 정수를 입력받을 배열
	int* parr[ARRLENGTH]; //배열의 각 요소의 주소값을 저장하고 sorting할 포인터배열
	int n=0; //몇 번째인지를 입력받을 변수

	printf("%d개의 정수를 입력하세요~~~~\n\n", ARRLENGTH);
	fillarr(arr); //배열을 인자로 받아 10개의 정수를 입력받고 배열에 저장하는 함수
	printf("입력하신 10개의 정수: ");
	printarr(arr); //입력한 10개의 정수를 정렬 없이 출력한다

	fillparrWitharr(parr, arr); //10개의 정수를 저장한 배열의 각 요소의 주소값을 포인터배열에 저장하는 함수
	sortparr(parr); //포인터배열을 받아서 오름차순 정렬하는 함수
	printf("오름차 정렬됨: ");
	printf("\n");
	printparr(parr); //정렬된 포인터배열을 이용해 정수를 저장한 배열을 출력하는 함수
	printf("\n일반 배열은 전혀 정렬되지 않았습니다.\n"); //일반 배열은 처음 저장 이후로 건들지 않았음을 어필함.
	printarr(arr);
	printf("\n");
	
	while (1) {
		printf("10개 중 몇 번째로 큰 정수를 출력할까요?, -----종료(0) : ");
		scanf_s("%d", &n, sizeof(int)); //몇 번째를 입력받음
		if (n == 0||n> ARRLENGTH ||n<0) { //입력받은 값의 범위를 지정해서 예외처리
			break;
		}
		getchar(); //버퍼에 남은 개행문자를 먹어주는 getchar()
		printf("%d 번째로 큰 정수는: %d\n",n,*(parr[ARRLENGTH -n]));
		//switch문을 쓰기 보다는 유효한 입력값을 바로 처리하여 기능을 구현했음
		//포인터배열을 참조값 기준으로 오름차 정렬했기때문에 n번째로 큰 값은 [배열길이-n]을 참조하면 된다.
	}
	system("pause");
	return 0;
}
void fillarr(int* arr) { //배열에 정수를 입력받는 함수
	int i = 0;
	for (i = 0; i < ARRLENGTH; i++) {
		printf("%d 번째 정수를 입력하세요~~~: ", i+1);
		scanf_s("%d", &arr[i], sizeof(int));
		getchar();
	}
}
void printarr(int* arr) { //입력받은 배열을 출력하는 함수
	int i = 0;
	for (i = 0; i < ARRLENGTH; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void fillparrWitharr(int** parr, int* arr) { //포인터배열을 이전에 입력받은 배열로 채우는 함수
	int i = 0;
	for (i = 0; i < ARRLENGTH; i++) {
		parr[i] = &arr[i]; //정수를 저장한 배열의 각 요소 주소를 대칭되는 포인터에 저장한다.
	}
}
void printparr(int** parr) { //포인터배열을 이용해서 정수를 저장한 배열을 출력하는 함수
	int i = 0;
	for (i = 0; i < ARRLENGTH; i++) {
		printf("%d ", *parr[i]); //저장해놓은 주소를 참조하여 출력함
	}
	printf("\n");
}
void sortparr(int** parr) { //포인터배열을 오름차 정렬하는 함수
	int i, j = 0;
	for (i = 0; i < ARRLENGTH; i++) { //선택정렬 알고리즘을 이용했다.
		for (j = i + 1; j < ARRLENGTH; j++) {
			if (*parr[i] > * parr[j]) { //정렬의 기준은 저장된 주소를 참조하여 얻은 값이다.
				int* temp = parr[i]; //참조값을 비교해 주소값을 정렬한다.
				parr[i] = parr[j];
				parr[j] = temp;
			}
		}
	}
}