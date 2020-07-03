#include <stdio.h>


typedef struct student {
    char name[10];
    char ID[20];
    char phone[20];
    char address[10];
 }STUDENT;
//과제에 사용할 구조체 선언.

STUDENT* enterStudentsInfo(); //정보를 입력할 때 사용할 함수.

int main() {
    int choice = 0; //switch-case를 쓰기 위한 변수
    STUDENT* students[100]; 
    //구조체포인터 100개짜리 배열을 선언했다.
    //정보가 추가될 때마다 동적할당할 생각이다.
    int studentsCounter = 0;
    //학생정보가 몇개인지 추적할 때 사용될 변수
    int i = 0;//출력하는 for문에 쓸 변수
    FILE* savefile; //파일을 다룰 파일포인터

    while (1) {//루프 안에 넣었다.
        printf("관리 옵션을 선택해 주세요\n1.정보입력\t2.전체학생출력\n3.끝내기\n: ");
        scanf_s("%d",&choice,sizeof(int));
        switch (choice) {
        case 1:
            if (studentsCounter < 100) { //100개를 넘으면 안되니까 예외처리 했다.

                students[studentsCounter] = enterStudentsInfo();
                //구조체 포인터에 동적할당한 주소를 담는다.
                //enterStudentsInfo함수는 STUDENT하나를 동적할당 후 정보를 입력받아 저장하고 STUDENT포인터를 리턴한다.
                //물론 heap에 있는 주소를 리턴하므로 dangling 포인터가 되지 않는다.

                fopen_s(&savefile,"students.txt", "a"); //정보가 저장될 때마다 텍스트파일에 기록한다. 파일이 없으면 새로 만든다.
                if (savefile == NULL) { //예외처리 해준다.
                    printf("파일열기 오류\n");
                    break;
                }
                fprintf(savefile, "%s  %s  %s  %s\n", students[studentsCounter]->name,
                    students[studentsCounter]->ID, students[studentsCounter]->phone,
                    students[studentsCounter]->address); //한 줄로 text파일에 기록한다.

                studentsCounter++; //정보 저장 처리가 다 끝나면 학생 수 하나를 올려준다.
                fclose(savefile); //열었던 파일을 닫는다.
                break;
            }
            else { //100개를 넘으면 이제 저장이 안된다.
                printf("저장소가 꽉찼읍니다.\n");
                break;
            }
        case 2://학생정보를 출력하는 부분은 심플하게 for문으로 구현했다.
            printf("=================================================\n");
            for (i = 0; i < studentsCounter; i++) {
                printf("이름: %s\n학번: %s\n번호: %s\n주소: %s\n\n", students[i]->name, students[i]->ID, students[i]->phone, students[i]->address);
            }
            printf("=================================================\n");
            break;
        case 3:
            for (i = 0; i < studentsCounter; i++) {
                free(students[i]);
            }
            //프로그램이 종료되기 전에 할당한 자리를 다 free해준다.
            //학생정보가 저장 될 때에만 동적할당이 이뤄지므로 학생 수만큼의 포인터만 free해주면 된다.
            break;
        default:
            break;
        }
    }

    return 0;
}

STUDENT* enterStudentsInfo() { //정보입력을 담당하는 함수.
    STUDENT* retData = (STUDENT*)malloc(sizeof(STUDENT));
    //리턴할 주소를 할당한다. 할당할 때에는 타입에 맞게 캐스팅해준다.
    printf("정보를 입력하세요.\n");
    printf("이름: "); scanf_s("%s", &retData->name, sizeof(retData->name)); printf("\n");
    printf("학번: "); scanf_s("%s", &retData->ID, sizeof(retData->ID)); printf("\n");
    printf("번호: "); scanf_s("%s", &retData->phone, sizeof(retData->phone)); printf("\n");
    printf("주소: "); scanf_s("%s", &retData->address, sizeof(retData->address)); printf("\n");
    //할당한 주소에 곧바로 데이터를 저장한다.
    return retData;//데이터까지 잘 저장된 주소를 리턴한다.
}