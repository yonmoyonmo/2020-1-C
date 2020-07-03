#include <stdio.h>
#include <math.h> //������ ������ ������

int decToDigit(int reversedBinArr[],int realBinArr[] ,int input) {
    //�迭 �ΰ��� �̿��� �������� �������� ��ȯ�ϰ� ��ȯ�� �������� �ڸ����� ������
    int i = 0; //iter
    int div = input; //��� 2�� ���� �Ŷ� �̸��� div�� ��
    for (i = 0; div >= 0; i++) {//div�� ���̻� 2�� �������� ���� ������ �ݺ�
        if (div == 1) { //���� ���� 1�̸� �װ��� �������� ù�ڸ� ����
            reversedBinArr[i] = div; //ù�ڸ� ���� �����ϰ�
            break;//�ݺ��� Ż��
        }
        reversedBinArr[i] = div % 2; //�ݺ��ؼ� �Է°��� 2�� ���� �������� ������
        div = div / 2; //div�� �ݺ��ؼ� 2�� �������� ������ �����
    }
    int j = 0;
    int cnt = i;
    for (j = 0; j <= cnt; j++) {
        realBinArr[j] = reversedBinArr[i];
        i--; //������ ������ �迭�� �������� �ٽ� �ٸ� �迭�� ����
    }
    return j; //��ȯ�� �������� �ڸ����� ������
}

void printBin(int realBinArr[], int bitCount) {
    int i = 0;
    for (i = 0; i < bitCount; i++) {
        if (realBinArr[i] == 0 || realBinArr[i] == 1) {
            printf("%d", realBinArr[i]);
        }
        else {
            printf("�Է��Ͻ� ���ڰ� �Ѹ� Ů�ϴ�.");
            break; //decToDigit���� �ʹ� ū ������ �Է¹޾� �Ҵ��� 32��¥�� int�迭�� �ѱ� ��� �����Ⱚ�� ����(0�̳� 1�� �ƴ�) �� ��� �ʹ� ū ���̱� ������ �̷��� ����ó����
        }
    }
    printf(" (%d �ڸ���)\n", i);
}

void zeroOrOne(int bin[], int count) { //�Է¹��� �ڸ����� ���� 0���� 1���� �˷���
    int i,x = 0;
    printf("\n\n��� �ڸ��� ���� �˰� �ͼ�?");
    scanf_s("%d", &i);
    getchar();
    if (i > 32) {
        printf("32��Ʈ �̻��� �������� �ʽ��ϴ�.");
        return;//����ó��
    }
    if (i > count) {
        printf("���� ���� ���� �������� %d��Ʈ�Դϴ�.(�ʰ��ߴ��̸��̾�)", count);
        return;//����ó��, �������� �������� �ڸ������� ū ���� �Է��� ���
    }
    x = bin[i-1];//�Է¹��� ���� -1�� �ؾ� �ùٸ� �ε����� ���� ����
    printf("\n %d �ڸ��� ���ڴ� %d �Դϴ�.    ", i, x);
}

void changeDigit(int bin[], int count) {
    int k = 0;
    printf("\n\n��� �ڸ��� ���� �ٲٽ�? :");
    scanf_s("%d", &k);
    getchar();
    if (k > 32) {
        printf("32��Ʈ �̻��� �������� �ʽ��ϴ�.");
        return;
    }
    if (k > count) {
        printf("���� ���� ���� �������� %d��Ʈ�Դϴ�.(�ʰ��ߴ��̸��̾�)", count);
        return;
    }
    bin[k-1] = 1;//�Է¹��� ���� -1�� �ؾ� �ùٸ� �ε����� ���� ����
    printf("%d �ڸ��� ���� 1�� �ٲ���ϴ�.\n", k);
}

void printDigitToDec(int bin[], int count) {
    int result = 0;
    int c = count-1;//2�� ������ 0���� �����ϱ⶧���� �迭 �ε��� ������ ��ó�� -1 ����
    int i = 0;
    for (i = 0; i < count && c!=-1; i++) {
        result += (bin[i] * (pow(2, c)));
        c--;
    }//�������� �������� ��ȯ�ϴ� �� ���
    printf("�������� ��ȯ�ϸ�: %d\n", result); //����ؼ� �����
}

int main(void) {
    int reversedBinArr[32]; //word size == 32bit, 10������ 2������ ��ȯ�� �� 0�� 1���� ������ �迭
    int realBinArr[32]; //�������� ����� �迭�� �ùٸ� �������� �ٽ� ������ �� �� �迭, �� �迭�� ���α׷� ���ᶧ ���� �����ϸ鼭 �����
    
    int input=0;
    printf("���� �ϳ� �Է� �ϼ��� : ");
    scanf_s("%d", &input, sizeof(int)); //���� �ϳ� �Է� ����

    int bitCount = decToDigit(reversedBinArr,realBinArr, input); //bitCount������ ��ȯ�� �������� ���ڸ� ������ ���
    printBin(realBinArr, bitCount);//�Է¹��� �������� ��ȯ�� �������� ����ϴ� �Լ�
    
    while (1) {//���� �� ������ �ݺ��ؼ� ��� ����
        int choice = 0;
        printf("\n\n========================\n1. 0�ϱ� 1�ϱ� \n2. 1�ιٲ� ������\n3. ����\n");
        scanf_s("%d", &choice, sizeof(int));
        switch (choice) {
        case 1:
            zeroOrOne(realBinArr, bitCount); //���� i�� �Է¹޾� i �ڸ��� ���� 0���� 1���� �˷��ִ� �Լ�
            printBin(realBinArr, bitCount); //���� �񱳸� ���� �� �� �� ���
            break;
        case 2:
            printBin(realBinArr, bitCount); //���� ���� �񱳸� ���� ���
            changeDigit(realBinArr, bitCount);//�Է¹��� �ڸ����� �ش��ϴ� ���� 1�� �ٲ���, �����ϰ��ִ� realBinArr�� ���� ������
            printBin(realBinArr, bitCount);//���� ���� �񱳸� ���� ���, ������ �������� ��µȴ�.
            printDigitToDec(realBinArr, bitCount);//������ �������� �������� ��ȯ�� ����Ѵ�.
            break;
        case 3:
            exit(0);
        default:
            break;
        }
    }
	return 0;
}