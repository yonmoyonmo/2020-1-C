#include <stdio.h>
#include <math.h> //제곱을 쓰려고 포함함

int decToDigit(int reversedBinArr[],int realBinArr[] ,int input) {
    //배열 두개를 이용해 십진수를 이진수로 변환하고 변환된 이진수의 자릿수를 리턴함
    int i = 0; //iter
    int div = input; //계속 2로 나눌 거라 이름을 div로 함
    for (i = 0; div >= 0; i++) {//div가 더이상 2로 나눠지지 않을 때까지 반복
        if (div == 1) { //나눈 몫이 1이면 그것이 이진수의 첫자리 수임
            reversedBinArr[i] = div; //첫자리 수를 저장하고
            break;//반복문 탈출
        }
        reversedBinArr[i] = div % 2; //반복해서 입력값을 2로 나눈 나머지를 저장함
        div = div / 2; //div는 반복해서 2로 나누어진 몫으로 저장됨
    }
    int j = 0;
    int cnt = i;
    for (j = 0; j <= cnt; j++) {
        realBinArr[j] = reversedBinArr[i];
        i--; //위에서 저장한 배열을 역순으로 다시 다른 배열에 저장
    }
    return j; //변환된 이진수의 자릿수를 리턴함
}

void printBin(int realBinArr[], int bitCount) {
    int i = 0;
    for (i = 0; i < bitCount; i++) {
        if (realBinArr[i] == 0 || realBinArr[i] == 1) {
            printf("%d", realBinArr[i]);
        }
        else {
            printf("입력하신 숫자가 넘모 큽니다.");
            break; //decToDigit에서 너무 큰 정수를 입력받아 할당한 32개짜리 int배열을 넘긴 경우 쓰레기값이 있음(0이나 1이 아님) 그 경우 너무 큰 값이기 때문에 이렇게 예외처리함
        }
    }
    printf(" (%d 자릿수)\n", i);
}

void zeroOrOne(int bin[], int count) { //입력받은 자릿수의 수가 0인지 1인지 알려줌
    int i,x = 0;
    printf("\n\n어느 자리의 수를 알고 싶소?");
    scanf_s("%d", &i);
    getchar();
    if (i > 32) {
        printf("32비트 이상은 지원하지 않습니다.");
        return;//예외처리
    }
    if (i > count) {
        printf("현재 유지 중인 이진수는 %d비트입니다.(초과했다이말이야)", count);
        return;//예외처리, 유지중인 이진수의 자릿수보다 큰 수를 입력한 경우
    }
    x = bin[i-1];//입력받은 수에 -1을 해야 올바른 인덱스로 접근 가능
    printf("\n %d 자리의 숫자는 %d 입니다.    ", i, x);
}

void changeDigit(int bin[], int count) {
    int k = 0;
    printf("\n\n어느 자리의 수를 바꾸쉴? :");
    scanf_s("%d", &k);
    getchar();
    if (k > 32) {
        printf("32비트 이상은 지원하지 않습니다.");
        return;
    }
    if (k > count) {
        printf("현재 유지 중인 이진수는 %d비트입니다.(초과했다이말이야)", count);
        return;
    }
    bin[k-1] = 1;//입력받은 수에 -1을 해야 올바른 인덱스로 접근 가능
    printf("%d 자리의 수를 1로 바꿨습니다.\n", k);
}

void printDigitToDec(int bin[], int count) {
    int result = 0;
    int c = count-1;//2의 지수가 0부터 시작하기때문에 배열 인덱스 접근할 때처럼 -1 해줌
    int i = 0;
    for (i = 0; i < count && c!=-1; i++) {
        result += (bin[i] * (pow(2, c)));
        c--;
    }//이진수를 십진수로 변환하는 식 계산
    printf("십진수로 변환하면: %d\n", result); //계산해서 출력함
}

int main(void) {
    int reversedBinArr[32]; //word size == 32bit, 10진수를 2진수로 변환할 때 0과 1들을 저장할 배열
    int realBinArr[32]; //역순으로 저장된 배열을 올바른 방향으로 다시 저장할 때 쓸 배열, 이 배열을 프로그램 종료때 까지 유지하면서 사용함
    
    int input=0;
    printf("정수 하나 입력 하세염 : ");
    scanf_s("%d", &input, sizeof(int)); //정수 하나 입력 받음

    int bitCount = decToDigit(reversedBinArr,realBinArr, input); //bitCount변수로 변환된 이진수가 몇자리 수인지 기록
    printBin(realBinArr, bitCount);//입력받은 십진수를 변환한 이진수를 출력하는 함수
    
    while (1) {//종료 할 때까지 반복해서 기능 수행
        int choice = 0;
        printf("\n\n========================\n1. 0일까 1일까 \n2. 1로바꾼 십진수\n3. 종료\n");
        scanf_s("%d", &choice, sizeof(int));
        switch (choice) {
        case 1:
            zeroOrOne(realBinArr, bitCount); //정수 i를 입력받아 i 자릿수 수가 0인지 1인지 알려주는 함수
            printBin(realBinArr, bitCount); //편한 비교를 위해 또 한 번 출력
            break;
        case 2:
            printBin(realBinArr, bitCount); //역시 편한 비교를 위해 출력
            changeDigit(realBinArr, bitCount);//입력받은 자릿수에 해당하는 수를 1로 바꿔줌, 유지하고있는 realBinArr를 직접 수정함
            printBin(realBinArr, bitCount);//역시 편한 비교를 위해 출력, 수정된 이진수가 출력된다.
            printDigitToDec(realBinArr, bitCount);//수정된 이진수를 십진수로 변환해 출력한다.
            break;
        case 3:
            exit(0);
        default:
            break;
        }
    }
	return 0;
}