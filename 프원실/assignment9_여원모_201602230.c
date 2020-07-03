#include <stdio.h>

typedef struct _IntLinked
{
	int num;
	struct _IntLinked* next;
}IntLinked;
//����Ʈ ��带 ����ü�� �����Ѵ�.

int main() {
	IntLinked* head = (IntLinked*)malloc(sizeof(IntLinked));
	//head�� �ʱ�ȭ �� �ش�. head���� �ǹ��ִ� ������ ������ ����Ʈ�� ������ ����ų �� ���� �ڵ带 ª�Ծ� �� �ִ�.
	head->num = -999; //Ȥ�ó� �Ǽ��� ������ �̷��� �� head�� �����͸� ���������� �� �� �ְ� �����͸� �ʱ�ȭ �Ѵ�.
	IntLinked* current; //IntLinked�����͸� �ϳ� ����ؼ� ���ͷ�����ó�� �� �����̴�.
	current = head; //�����Ͱ� �ƹ� �͵� ���� ���� head�� ����Ų��.

	int listNodesCount = 0; //����� ������ �Է¹��� ����
	int i = 0; //�ݺ����� �� ����

	printf("������ ����Ʈ�� ���� �Է�: "); 
	scanf_s("%d", &listNodesCount, sizeof(listNodesCount));
	if (listNodesCount <= 0) { 
		//0�� ���� ��� �̻��� �ּҸ� �����ϰ� �Ǿ� �����ϴ� ����ó����.
		printf("�㰡���� ���� �Է��Դϴ�.\n");
		return 1;
	}
	printf("\n");
	
	for (i = 0; i < listNodesCount; i++) { //�Էµ� ������ŭ ��带 �����Ҵ� �Ѵ�.
		current->next = (IntLinked*)malloc(sizeof(IntLinked)); //head�� next���� �����Ͱ� �Էµȴ�.
		printf("������ �Է��ϼ��� : ");
		scanf_s("%d", &current->next->num, sizeof(int));
		current->next->next = NULL; //���� �Ҵ�� ���� �׻� ���� ������ ����̹Ƿ� ���� �����Ͱ� ������ ������ش�.
		current = current->next; 
		//current �����͸� ���� �Ҵ��� ���� �Ű��ش�
		//�̷��� �ϸ� current�� �׻� ���� ���� ��带 ����Ű�� �ȴ�.
		//�׷��� �׻� ����Ʈ�� ���� ���ο� ������ ������ �� �ִ�.
	}
	
	current = head->next; //����� �����͸� ����ϱ� ���� current�����͸� ���� ó�� ���� �ű��.
	for (i = 0; i < listNodesCount; i++) { //�Է��ߴ� Ƚ����ŭ�� �ݺ��Ѵ�.
		printf("����� ����: %d\n", current->num); //current�� ����Ű�� ����� �����͸� ����Ѵ�.
		current = current->next; //current�����͸� �� ĭ �Űܼ� ���� �ݺ��� �ٸ� �����͸� ����� �� �ְ� �Ѵ�.
	}

	current = head; //�����Ҵ� �ߴ� �޸𸮸� �����ϱ� ���� current�� head�� ����Ű�� �Ѵ�.
	//head�� �Ҵ�� ������ �ֱ⶧���� ���� free�ؾ� �ϱ⶧���̴�.
	IntLinked* deleteHelper;
	//current�� free�� ������ ���� �ּҸ� �� ���� �����Ƿ�
	//deleteHelper�� �����ؼ� ������ �ּҸ� ��� current�� �ű�鼭 �Ҵ�� ������ �����Ѵ�.
	for (i = 0; i <= listNodesCount; i++) {
		//������ �޸𸮰� �Էµ� ���� + 1(head�� �޸𸮵� �����ؾ���)���� �����ϸ鼭 �ݺ�Ƚ���� ���Ѵ�.
		deleteHelper = current; //������ �ּҸ� ����Ű�� �Ѵ�.
		current = current->next; //current�� ������ ������ ���� ����Ų��.
		if (current->next == NULL) { //Ȥ�ö� null�̸� �ݺ��� �����. 
			break;
		}
		free(deleteHelper); //������ ���� ���� current�� ����Ű�� �����Ƿ� �������� free�Ѵ�.
	}

	return 0;
}

