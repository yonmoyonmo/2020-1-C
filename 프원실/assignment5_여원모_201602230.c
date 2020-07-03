#include <stdio.h>
#define TRUE 1
#define FALSE 0

int isPrime(int n); //���ʴ�� �����ϱ� ���ؼ� �Լ����� ���漱����.
int primeFactorize(int* primes, int n);
static int primeArrCounter = 0; //���ǹ��� ��(���μ���)�� ������ ī���� �� ����.

int main(void) {
	int n;//�̰��� �Է¹��� ����.
	int primefactors[200];//���μ����� ���� �迭, ���μ����� �Լ� ���ο��� ���μ����� ������ �� �����.
							//�Լ� ���ο��� ��������� ���μ��� ����ϱ� ������ ���� ���μ����� ��Ƴ��� ������ ������
							//�迭������ �迭�� ������ �����ϱ� ������ ����.
	int i = 0;
	for (i = 0; i < 200; i++) {//�迭�ʱ�ȭ����
		primefactors[i] = 0;
	}

	printf("���� �Է�: "); 
	scanf_s("%d", &n);//�Է� ����
	if (isPrime(n)==TRUE) { //�Է¹��� ���� �Ҽ����� Ȯ��
		printf("�Ҽ��Դϴ�.\n");
		system("PAUSE");
		return 0;// �Ҽ��� ����.
	}
	printf("%d=", n);
	primeFactorize(primefactors, n);//���μ����� �Լ�, ��������� ���μ��� ����(������)
	//�迭�� �Է¹��� �ռ����� �Ѱ� �ָ� �迭�� �� �ռ����� ���μ��� ä���ش�.
	printf("\n");
	system("PAUSE");
	return 0;
}

int isPrime(int n) { //�Ҽ����� �ƴ��� �Ǵ��ϴ� �Լ�
	int i = 0; //2���� n-1������ ������ n�� ������ �� �� �������� ���� �ִٸ� n�� �Ҽ��� �ƴ�.
	int x = 0;
	for (i = 2; i < n; i++) {
		x = n % i;
		if (x == 0) return FALSE;
	}
	return TRUE;
}

int primeFactorize(int* primes, int n) { //���μ����� �Լ�
	if (isPrime(n) == TRUE) {
		primes[primeArrCounter] = n;
		primeArrCounter++;
		printf("*%d", n);
		return TRUE;
	}//->Ż������: n�� �Ҽ��� ���

	int p = 0;
	for (p = 2; p < n; p++) {
		if (isPrime(p) == TRUE) {				//�Ҽ��� �ƴ϶�� ���� ����.
			if (n % p == 0) {					//p�� ���� �� �������� ����� ��.
				n = n / p;						//n�� p�� ���� ���� �ٽ� n�� �ְ�
				primes[primeArrCounter] = p;	//���μ��迭�� ���μ��� ����
				primeArrCounter++;				//���μ��� �߰��� ������ �� ������.
				if (primeArrCounter == 1) {		//������ ���� ����ϱ� ���ؼ�
					printf("%d", p);			//ó�� ���μ��� *�� ������� �ʰ� ����.
				}
				else {
					printf("*%d", p);
				}
				return primeFactorize(primes, n);//p�� ������ n�� �̿��� �ٽ� ���ȣ����.
			}
		}
	}
	return FALSE;
}