#include <stdio.h>

typedef struct _IntLinked
{
	int num;
	struct _IntLinked* next;
}IntLinked;
//리스트 노드를 구조체로 선언한다.

int main() {
	IntLinked* head = (IntLinked*)malloc(sizeof(IntLinked));
	//head를 초기화 해 준다. head에는 의미있는 정보는 없지만 리스트의 시작을 가리킬 때 쓰면 코드를 짧게쓸 수 있다.
	head->num = -999; //혹시나 실수로 참조가 이뤄질 때 head의 데이터를 참조했음을 알 수 있게 데이터를 초기화 한다.
	IntLinked* current; //IntLinked포인터를 하나 사용해서 이터레이터처럼 쓸 생각이다.
	current = head; //데이터가 아무 것도 없을 때엔 head를 가리킨다.

	int listNodesCount = 0; //노드의 갯수를 입력받을 변수
	int i = 0; //반복문에 쓸 변수

	printf("생성할 리스트의 개수 입력: "); 
	scanf_s("%d", &listNodesCount, sizeof(listNodesCount));
	if (listNodesCount <= 0) { 
		//0이 들어올 경우 이상한 주소를 참조하게 되어 위험하니 예외처리함.
		printf("허가되지 않은 입력입니다.\n");
		return 1;
	}
	printf("\n");
	
	for (i = 0; i < listNodesCount; i++) { //입력된 갯수만큼 노드를 동적할당 한다.
		current->next = (IntLinked*)malloc(sizeof(IntLinked)); //head의 next부터 데이터가 입력된다.
		printf("정수를 입력하세요 : ");
		scanf_s("%d", &current->next->num, sizeof(int));
		current->next->next = NULL; //새로 할당된 노드는 항상 제일 마지막 노드이므로 다음 데이터가 없음을 명시해준다.
		current = current->next; 
		//current 포인터를 새로 할당한 노드로 옮겨준다
		//이렇게 하면 current가 항상 제일 끝의 노드를 가리키게 된다.
		//그래서 항상 리스트의 끝에 새로운 정보를 저장할 수 있다.
	}
	
	current = head->next; //저장된 데이터를 출력하기 위해 current포인터를 제일 처음 노드로 옮긴다.
	for (i = 0; i < listNodesCount; i++) { //입력했던 횟수만큼만 반복한다.
		printf("저장된 정수: %d\n", current->num); //current가 가리키는 노드의 데이터를 출력한다.
		current = current->next; //current포인터를 한 칸 옮겨서 다음 반복엔 다른 데이터를 출력할 수 있게 한다.
	}

	current = head; //동적할당 했던 메모리를 해제하기 위해 current가 head를 가리키게 한다.
	//head도 할당된 영역이 있기때문에 같이 free해야 하기때문이다.
	IntLinked* deleteHelper;
	//current를 free해 버리면 다음 주소를 알 수가 없으므로
	//deleteHelper를 선언해서 해제할 주소를 담고 current를 옮기면서 할당된 영역을 해제한다.
	for (i = 0; i <= listNodesCount; i++) {
		//해제할 메모리가 입력된 갯수 + 1(head의 메모리도 해제해야함)임을 인지하면서 반복횟수를 정한다.
		deleteHelper = current; //해제할 주소를 가리키게 한다.
		current = current->next; //current는 다음에 해제할 곳을 가리킨다.
		if (current->next == NULL) { //혹시라도 null이면 반복을 멈춘다. 
			break;
		}
		free(deleteHelper); //다음에 지울 곳을 current가 가리키고 있으므로 마음편히 free한다.
	}

	return 0;
}

