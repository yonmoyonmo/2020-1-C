#include <stdio.h>

int main(void) {
	int id_num = 0; //�й�
	int score[5]; //���� �迭
	int sum = 0; //�հ谪

	int i = 0; // �ݺ���
	for (i = 0; i < 5; i++) {
		score[i] = 0;
	}//�迭 �ʱ�ȭ

	printf("�й��� �Է��ϼ���\n");
	scanf_s("%d",&id_num);
	//�й� �Է� �ޱ�

	printf("\n���� �Է� �ϼ���\n");
	for (i = 0; i < 5; i++) {
		printf("���� %d :", 1+i);
		scanf_s("%d", &score[i]);
		sum += score[i];
	}//���� �Է� �޾Ƽ� �迭�� �ְ� �հ��� ������

	printf("%d ���� ����ǥ�� �Ʒ��� �����ϴ�\n--------------------------\n", id_num);
	for (i = 0; i < 5; i++) {
		printf("���� %d : %d \n", i+1, score[i]);
	}//�Է� ���� ���� ���
	float avg = sum / 5.0;
	printf("---------------------------------\n��� : %f\n-------------------------------------", avg);
	//�հ谪�� ���� ���� ������ ��� ���
}