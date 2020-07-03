#include <stdio.h>


typedef struct student {
    char name[10];
    char ID[20];
    char phone[20];
    char address[10];
 }STUDENT;
//������ ����� ����ü ����.

STUDENT* enterStudentsInfo(); //������ �Է��� �� ����� �Լ�.

int main() {
    int choice = 0; //switch-case�� ���� ���� ����
    STUDENT* students[100]; 
    //����ü������ 100��¥�� �迭�� �����ߴ�.
    //������ �߰��� ������ �����Ҵ��� �����̴�.
    int studentsCounter = 0;
    //�л������� ����� ������ �� ���� ����
    int i = 0;//����ϴ� for���� �� ����
    FILE* savefile; //������ �ٷ� ����������

    while (1) {//���� �ȿ� �־���.
        printf("���� �ɼ��� ������ �ּ���\n1.�����Է�\t2.��ü�л����\n3.������\n: ");
        scanf_s("%d",&choice,sizeof(int));
        switch (choice) {
        case 1:
            if (studentsCounter < 100) { //100���� ������ �ȵǴϱ� ����ó�� �ߴ�.

                students[studentsCounter] = enterStudentsInfo();
                //����ü �����Ϳ� �����Ҵ��� �ּҸ� ��´�.
                //enterStudentsInfo�Լ��� STUDENT�ϳ��� �����Ҵ� �� ������ �Է¹޾� �����ϰ� STUDENT�����͸� �����Ѵ�.
                //���� heap�� �ִ� �ּҸ� �����ϹǷ� dangling �����Ͱ� ���� �ʴ´�.

                fopen_s(&savefile,"students.txt", "a"); //������ ����� ������ �ؽ�Ʈ���Ͽ� ����Ѵ�. ������ ������ ���� �����.
                if (savefile == NULL) { //����ó�� ���ش�.
                    printf("���Ͽ��� ����\n");
                    break;
                }
                fprintf(savefile, "%s  %s  %s  %s\n", students[studentsCounter]->name,
                    students[studentsCounter]->ID, students[studentsCounter]->phone,
                    students[studentsCounter]->address); //�� �ٷ� text���Ͽ� ����Ѵ�.

                studentsCounter++; //���� ���� ó���� �� ������ �л� �� �ϳ��� �÷��ش�.
                fclose(savefile); //������ ������ �ݴ´�.
                break;
            }
            else { //100���� ������ ���� ������ �ȵȴ�.
                printf("����Ұ� ��á���ϴ�.\n");
                break;
            }
        case 2://�л������� ����ϴ� �κ��� �����ϰ� for������ �����ߴ�.
            printf("=================================================\n");
            for (i = 0; i < studentsCounter; i++) {
                printf("�̸�: %s\n�й�: %s\n��ȣ: %s\n�ּ�: %s\n\n", students[i]->name, students[i]->ID, students[i]->phone, students[i]->address);
            }
            printf("=================================================\n");
            break;
        case 3:
            for (i = 0; i < studentsCounter; i++) {
                free(students[i]);
            }
            //���α׷��� ����Ǳ� ���� �Ҵ��� �ڸ��� �� free���ش�.
            //�л������� ���� �� ������ �����Ҵ��� �̷����Ƿ� �л� ����ŭ�� �����͸� free���ָ� �ȴ�.
            break;
        default:
            break;
        }
    }

    return 0;
}

STUDENT* enterStudentsInfo() { //�����Է��� ����ϴ� �Լ�.
    STUDENT* retData = (STUDENT*)malloc(sizeof(STUDENT));
    //������ �ּҸ� �Ҵ��Ѵ�. �Ҵ��� ������ Ÿ�Կ� �°� ĳ�������ش�.
    printf("������ �Է��ϼ���.\n");
    printf("�̸�: "); scanf_s("%s", &retData->name, sizeof(retData->name)); printf("\n");
    printf("�й�: "); scanf_s("%s", &retData->ID, sizeof(retData->ID)); printf("\n");
    printf("��ȣ: "); scanf_s("%s", &retData->phone, sizeof(retData->phone)); printf("\n");
    printf("�ּ�: "); scanf_s("%s", &retData->address, sizeof(retData->address)); printf("\n");
    //�Ҵ��� �ּҿ� ��ٷ� �����͸� �����Ѵ�.
    return retData;//�����ͱ��� �� ����� �ּҸ� �����Ѵ�.
}