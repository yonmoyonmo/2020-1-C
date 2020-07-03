/*월급 = (시간급여 * 총 근무시간) * (1 – 세율)

부장 – 시간당 9,200원, 세금 12%
사원 – 시간당 6,300원, 세금 9%

부장 1명과 사원 1명 각각의 이름(문자열)과 총 근무시간(정수)을 입력 받아서,
회사가 지출해야 할 월급을 각각 계산하여 출력

시급과 세금은 기호상수를 사용하도록 함
*/
#include <stdio.h>

#define boojang_pay 9200 //상술 한 내용 기호상수 선언
#define boojang_tax 0.12
#define sawon_pay 6300
#define sawon_tax 0.09

void pay_calcul() {
	char boojang[30]; //데이터 저장을 위한 변수들 선언
	char sawon[30];
	int boojang_time = 0;
	int sawon_time = 0;

	printf("부장의 이름을 입력하세요 : ");
	gets(boojang); //문자열 입력은 gets로
	printf("부장의 근무시간을 입력하세요 : ");
	scanf_s("%d", &boojang_time); //정수입력은 scanf로
	getchar(); //버퍼 클리어

	printf("\n");

	printf("사원의 이름을 입력하세요 : ");
	gets(sawon);
	printf("사원의 근무시간을 입력하세요 : ");
	scanf_s("%d", &sawon_time);
	getchar();

	printf("======================================\n");
	int boojang_result = (boojang_pay * boojang_time) * (1 - boojang_tax);
	//암묵적인 형변환이 있어 소수와 정수 계산이 소수점 내림으로 진행됨
	int sawon_result = (sawon_pay * sawon_time) * (1 - sawon_tax);
	printf("%s 부장님의 월급은 %d 원 입니다.\n", boojang, boojang_result);
	printf("%s 사원님의 월급은 %d 원 입니다.\n", sawon, sawon_result);
	printf("======================================\n");
	int sum = boojang_result + sawon_result;
	printf("회사가 지불할 총 월급은 %d 원 입니다.\n", sum);
	system("PAUSE");//결과 확인을 위해 일시정지
}

int main(void) {
	pay_calcul(); //메인함수 내부에서 하나의 함수 호출로 기능 이용
	return 0;
}