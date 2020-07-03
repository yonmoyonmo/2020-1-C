#include <stdio.h>

int main(void) {
	int id_num = 0; //학번
	int score[5]; //점수 배열
	int sum = 0; //합계값

	int i = 0; // 반복자
	for (i = 0; i < 5; i++) {
		score[i] = 0;
	}//배열 초기화

	printf("학번을 입력하세요\n");
	scanf_s("%d",&id_num);
	//학번 입력 받기

	printf("\n점수 입력 하세요\n");
	for (i = 0; i < 5; i++) {
		printf("과목 %d :", 1+i);
		scanf_s("%d", &score[i]);
		sum += score[i];
	}//점수 입력 받아서 배열에 넣고 합계해 나가기

	printf("%d 님의 성적표는 아래와 같습니다\n--------------------------\n", id_num);
	for (i = 0; i < 5; i++) {
		printf("과목 %d : %d \n", i+1, score[i]);
	}//입력 받은 과목 출력
	float avg = sum / 5.0;
	printf("---------------------------------\n평균 : %f\n-------------------------------------", avg);
	//합계값을 과목 수로 나눠서 평균 출력
}