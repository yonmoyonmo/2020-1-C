#include <stdio.h>

void add(void) {
    int a, b = 0;
    printf("더할 수 두개를 입력 하십시오 <left + right>: ");
    scanf_s("%d",&a,sizeof(int));
    getchar();
    scanf_s("%d", &b, sizeof(int));
    getchar();
    printf("\n계산 결과: %d\n\n============================\n\n", a + b);
}
void sub(void) {
    int a, b = 0;
    printf("뺄 수 두개를 입력 하십시오 <left - right>: ");
    scanf_s("%d", &a, sizeof(int));
    getchar();
    scanf_s("%d", &b, sizeof(int));
    getchar();
    printf("\n계산 결과: %d\n\n============================\n\n", a - b);
}
void mul(void) {
    int a, b = 0;
    printf("곱할 수 두개를 입력 하십시오 <left * right>: ");
    scanf_s("%d", &a, sizeof(int));
    getchar();
    scanf_s("%d", &b, sizeof(int));
    getchar();
    printf("\n계산 결과: %d\n\n============================\n\n", a * b);
}
void div(void) {
    int a, b = 0;
    printf("나눌 수 두개를 입력 하십시오 <left / right>: ");
    scanf_s("%d", &a, sizeof(int));
    getchar();
    scanf_s("%d", &b, sizeof(int));
    getchar();
    printf("\n계산 결과: %d\n\n============================\n\n", a / b);
}

int fac(int n) {
    if (n == 1) {
        return n;
    }
    return n * fac(n - 1);
}

int main(void) {
    int f = 0; //팩토리얼을 위한 변수
    while (1) { //종료입력이 있기 전까지 무한 반복함
        char operator='a';//일단 a로 초기화
        printf("_____________계산기_____________\n지원하는 연산 +, -, *, /, !\n지원하는 항 갯수 2개\n 'q' 는 종료 \n연산자를 입력하세요: ");
        scanf_s("%c", &operator);
        getchar();
        switch (operator) { //입력받은 연산자에 따라 연산
        //+, -, *, / 연산은 함수 내부에서 계산결과를 출력하고 종료되는 형태입니다.
        case '+':
            add(); //더하기
            break;
        case '-':
           sub(); //빼기
            break;
        case '*':
            mul(); //곱하기
            break;
        case '/':
            div(); //나누기
            break;
        case '!': //팩토리얼
            printf("\nfac 할 수를 입력 하십시오 (최대 16) : "); //재귀호출 되는 fac함수를 가볍게 하기 위해 입력을 main에서 받음.
            scanf_s("%d", &f, sizeof(int));
            getchar();
            if (f > 16) {
                printf("입력하신 숫자를 ! 하면 넘 커져여"); //int형 변수에 담을 수 있는 한계를 넘어서면 예외처리함
                break;
            }
            printf("\n%d의 ! 는 %d\n",f,fac(f)); //결과값 출력, f는 계속 재활용 할 수 있도록 0으로 초기화 해주어서 관리
            f = 0;
            break;
        case 'q':
            exit(0);
        default:
            printf("\n\n<<<<<<<<<< 연산자를 잘못 입력하였습니다. >>>>>>>>>>>\n\n"); //지원하는 문자 외에 입력은 default로 예외처리
            break;
        }
    }
}