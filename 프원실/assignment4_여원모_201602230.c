#include <stdio.h>

void add(void) {
    int a, b = 0;
    printf("���� �� �ΰ��� �Է� �Ͻʽÿ� <left + right>: ");
    scanf_s("%d",&a,sizeof(int));
    getchar();
    scanf_s("%d", &b, sizeof(int));
    getchar();
    printf("\n��� ���: %d\n\n============================\n\n", a + b);
}
void sub(void) {
    int a, b = 0;
    printf("�� �� �ΰ��� �Է� �Ͻʽÿ� <left - right>: ");
    scanf_s("%d", &a, sizeof(int));
    getchar();
    scanf_s("%d", &b, sizeof(int));
    getchar();
    printf("\n��� ���: %d\n\n============================\n\n", a - b);
}
void mul(void) {
    int a, b = 0;
    printf("���� �� �ΰ��� �Է� �Ͻʽÿ� <left * right>: ");
    scanf_s("%d", &a, sizeof(int));
    getchar();
    scanf_s("%d", &b, sizeof(int));
    getchar();
    printf("\n��� ���: %d\n\n============================\n\n", a * b);
}
void div(void) {
    int a, b = 0;
    printf("���� �� �ΰ��� �Է� �Ͻʽÿ� <left / right>: ");
    scanf_s("%d", &a, sizeof(int));
    getchar();
    scanf_s("%d", &b, sizeof(int));
    getchar();
    printf("\n��� ���: %d\n\n============================\n\n", a / b);
}

int fac(int n) {
    if (n == 1) {
        return n;
    }
    return n * fac(n - 1);
}

int main(void) {
    int f = 0; //���丮���� ���� ����
    while (1) { //�����Է��� �ֱ� ������ ���� �ݺ���
        char operator='a';//�ϴ� a�� �ʱ�ȭ
        printf("_____________����_____________\n�����ϴ� ���� +, -, *, /, !\n�����ϴ� �� ���� 2��\n 'q' �� ���� \n�����ڸ� �Է��ϼ���: ");
        scanf_s("%c", &operator);
        getchar();
        switch (operator) { //�Է¹��� �����ڿ� ���� ����
        //+, -, *, / ������ �Լ� ���ο��� ������� ����ϰ� ����Ǵ� �����Դϴ�.
        case '+':
            add(); //���ϱ�
            break;
        case '-':
           sub(); //����
            break;
        case '*':
            mul(); //���ϱ�
            break;
        case '/':
            div(); //������
            break;
        case '!': //���丮��
            printf("\nfac �� ���� �Է� �Ͻʽÿ� (�ִ� 16) : "); //���ȣ�� �Ǵ� fac�Լ��� ������ �ϱ� ���� �Է��� main���� ����.
            scanf_s("%d", &f, sizeof(int));
            getchar();
            if (f > 16) {
                printf("�Է��Ͻ� ���ڸ� ! �ϸ� �� Ŀ����"); //int�� ������ ���� �� �ִ� �Ѱ踦 �Ѿ�� ����ó����
                break;
            }
            printf("\n%d�� ! �� %d\n",f,fac(f)); //����� ���, f�� ��� ��Ȱ�� �� �� �ֵ��� 0���� �ʱ�ȭ ���־ ����
            f = 0;
            break;
        case 'q':
            exit(0);
        default:
            printf("\n\n<<<<<<<<<< �����ڸ� �߸� �Է��Ͽ����ϴ�. >>>>>>>>>>>\n\n"); //�����ϴ� ���� �ܿ� �Է��� default�� ����ó��
            break;
        }
    }
}