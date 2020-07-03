#include <stdio.h>
#define ARRLENGTH 10 //�迭�� ���̸� ��ĥ ���� ����ؼ� define �ߴ�.


//�Լ��� ���� �ּ��� �Լ� ���ǿ���...
void fillarr(int* arr);
void printarr(int* arr);
void fillparrWitharr(int** parr, int* arr);
void printparr(int** parr);
void sortparr(int** parr);

int main(void) {
	int arr[ARRLENGTH]; //10���� ������ �Է¹��� �迭
	int* parr[ARRLENGTH]; //�迭�� �� ����� �ּҰ��� �����ϰ� sorting�� �����͹迭
	int n=0; //�� ��°������ �Է¹��� ����

	printf("%d���� ������ �Է��ϼ���~~~~\n\n", ARRLENGTH);
	fillarr(arr); //�迭�� ���ڷ� �޾� 10���� ������ �Է¹ް� �迭�� �����ϴ� �Լ�
	printf("�Է��Ͻ� 10���� ����: ");
	printarr(arr); //�Է��� 10���� ������ ���� ���� ����Ѵ�

	fillparrWitharr(parr, arr); //10���� ������ ������ �迭�� �� ����� �ּҰ��� �����͹迭�� �����ϴ� �Լ�
	sortparr(parr); //�����͹迭�� �޾Ƽ� �������� �����ϴ� �Լ�
	printf("������ ���ĵ�: ");
	printf("\n");
	printparr(parr); //���ĵ� �����͹迭�� �̿��� ������ ������ �迭�� ����ϴ� �Լ�
	printf("\n�Ϲ� �迭�� ���� ���ĵ��� �ʾҽ��ϴ�.\n"); //�Ϲ� �迭�� ó�� ���� ���ķ� �ǵ��� �ʾ����� ������.
	printarr(arr);
	printf("\n");
	
	while (1) {
		printf("10�� �� �� ��°�� ū ������ ����ұ��?, -----����(0) : ");
		scanf_s("%d", &n, sizeof(int)); //�� ��°�� �Է¹���
		if (n == 0||n> ARRLENGTH ||n<0) { //�Է¹��� ���� ������ �����ؼ� ����ó��
			break;
		}
		getchar(); //���ۿ� ���� ���๮�ڸ� �Ծ��ִ� getchar()
		printf("%d ��°�� ū ������: %d\n",n,*(parr[ARRLENGTH -n]));
		//switch���� ���� ���ٴ� ��ȿ�� �Է°��� �ٷ� ó���Ͽ� ����� ��������
		//�����͹迭�� ������ �������� ������ �����߱⶧���� n��°�� ū ���� [�迭����-n]�� �����ϸ� �ȴ�.
	}
	system("pause");
	return 0;
}
void fillarr(int* arr) { //�迭�� ������ �Է¹޴� �Լ�
	int i = 0;
	for (i = 0; i < ARRLENGTH; i++) {
		printf("%d ��° ������ �Է��ϼ���~~~: ", i+1);
		scanf_s("%d", &arr[i], sizeof(int));
		getchar();
	}
}
void printarr(int* arr) { //�Է¹��� �迭�� ����ϴ� �Լ�
	int i = 0;
	for (i = 0; i < ARRLENGTH; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void fillparrWitharr(int** parr, int* arr) { //�����͹迭�� ������ �Է¹��� �迭�� ä��� �Լ�
	int i = 0;
	for (i = 0; i < ARRLENGTH; i++) {
		parr[i] = &arr[i]; //������ ������ �迭�� �� ��� �ּҸ� ��Ī�Ǵ� �����Ϳ� �����Ѵ�.
	}
}
void printparr(int** parr) { //�����͹迭�� �̿��ؼ� ������ ������ �迭�� ����ϴ� �Լ�
	int i = 0;
	for (i = 0; i < ARRLENGTH; i++) {
		printf("%d ", *parr[i]); //�����س��� �ּҸ� �����Ͽ� �����
	}
	printf("\n");
}
void sortparr(int** parr) { //�����͹迭�� ������ �����ϴ� �Լ�
	int i, j = 0;
	for (i = 0; i < ARRLENGTH; i++) { //�������� �˰����� �̿��ߴ�.
		for (j = i + 1; j < ARRLENGTH; j++) {
			if (*parr[i] > * parr[j]) { //������ ������ ����� �ּҸ� �����Ͽ� ���� ���̴�.
				int* temp = parr[i]; //�������� ���� �ּҰ��� �����Ѵ�.
				parr[i] = parr[j];
				parr[j] = temp;
			}
		}
	}
}