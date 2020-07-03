#include <stdio.h>
#include <string.h>

void enterString(char* input); //���ڿ��� �Է¹޴� �Լ�
void printProcessedString(char* input, char* output); //���ڿ��� ó���ϴ� �Լ�
char checkString(char* input);//���ڿ��� �˻��ؼ� , . quit�� ã�Ƴ��� �Լ�
void myStrtok(char* input, const char cutter, char* beforeCutter, char* afterCutter); 
//strtok_s�Լ��� �ȵǼ� �������� �߸� strtok

int main() {
    char input[200]=" ";
    //���ڿ��� �Է¹޾� ������ ����
    char output[200]=" ";
    //�Է� ���� ���ڿ��� ó���� �� ���� ����� �� ���ڿ��� ������ ����
    
    while (1){
        enterString(input);//���ڿ��� �Է¹޴´�.
        printProcessedString(input, output);//���ڿ��� ó���Ѵ�.
        if (checkString(input) == 'q') return 0;//���࿡ quit�� �ܵ����� �ԷµǾ��ٸ� ���α׷��� �����Ѵ�.
    }

    return 0;
}

void enterString(char* input) {
    //�Էºθ� �Լ��� ���� ���ƾ� ���� ���ϴ�.
    printf("������ �Է��ϼ���. > ");
    gets(input);
}

void printProcessedString(char* input, char* output) {
    char beforeCutter[200]; //���й��� ������ ���ڿ��� ������ ����
    char afterCutter[200]; //���й��� ������ ���ڿ��� ������ ����
    char cutter; //���й��ڰ� �� ����

    if (checkString(input) == ',') { //���ڿ� �� ','�� �ִ� ���
        cutter = ','; //���й��ڸ� ','�� �����ϰ�
        myStrtok(input, cutter, beforeCutter, afterCutter); 
        //���ڿ��� ���й��� �������� ���ڿ��� �ݶ����ִ� �Լ��� ����ִ´�.
        strcpy_s(output,200,afterCutter);
        //�ݶ��� ���ڿ� �� ���й��� �޺κ��� ���� ������� �� ���ڿ��� �����Ѵ�.
        strcat_s(output, 200, ", ");
        //���ڿ��� �����ٰ� ����� ',' �� �߰����ش�.
        strcat_s(output, 200, beforeCutter);
        //���� ����� ���ڿ��� �ݶ��� �պκ��� �ٿ��ش�.
        printf("�������\n%s\n",output);
    }
    else if (checkString(input) == '.') {//���ڿ� �� '.'�� �ִ� ���
        cutter = '.'; //���й��ڸ� �����Ѵ�.
        myStrtok(input, cutter, beforeCutter, afterCutter);
        //���й��ڸ� �������� ������ ������.
        strcpy_s(output,200, beforeCutter);
        //������ ���� �պκ��� ���� �����Ѵ�.
        strcat_s(output, 200, " \n");
        //���๮�ڸ� �־��ش�.
        strcat_s(output, 200, afterCutter);
        //�޺κ��� ���δ�.
        printf("�������\n%s\n", output);
    }
    else printf("%s\n", input);
}

void myStrtok(char* input, const char cutter, char* beforeCutter, char* afterCutter) {
    /****************************************************************
    char* strtok_s(char* str, const char* delimiters, char** context)
    �Լ��� ������ �ߴµ� �ùٷ� ����ص� ������������ ��� �Ͼ��
    �и��� ���� �Ǽ��ϰŶ� �����ϸ� ������ ������� ������
    ���� ���� �������� ������ ã�� �� �������Ƿ�
    ������ ���� �߸� strtok�� �����ߴ�.
    �̸��� strtok�̰� ���ӻ��� �������̴�.
    �ڸ� ���ڿ� �ϳ�, ���й��� �ϳ�, �� ���ڿ� ���� �ѱ��
    ���й��� �ϳ��� �������� �� �ڷ� ���ڿ��� ������ �������ش�.
    *****************************************************************/
    
    int i = 0; //���й����� ��ġ �ε����� ��Ÿ�� �����̴�.
    while (input[i] != '\0') {
        if (input[i] == cutter) {
            break;
        }//���й��ڸ� ������ ������ ����������.
        ++i;
    } //���� i�� input���� ���й��ڰ� �ִ� ��ġ�� �ε����� ��Ÿ����.
    int j = 0;
    for (j = 0; j < i; j++) { 
        //input���� i������(���й��� ��) �����ؼ� ����
        beforeCutter[j] = input[j];
        beforeCutter[j + 1] = '\0'; //�ι��� �־�� ���ڿ��� �ȴ�.
    }

    j = 0;
    while (input[i] != '\0') {
        //���й���+1���� ������ �����ؼ� ������  
        afterCutter[j] = input[i+1];
        ++i;
        ++j;
    } 
    afterCutter[j + 1] = '\0';//���������� �ι��ڸ� �־��ش�.
}


char checkString(char* input) {
    //���ڿ��� ',' '.' "quit"�� Ȯ���ϴ� �Լ�
    //ã�� ���ڸ� �����Ѵ�.
    int length = strlen(input);
    int i = 0;
    for (i = 0; i < length; i++) {
        if (input[i] == ',') return ',';
        if (input[i] == '.') return '.';
    }
    if (input[0] == 'q' && input[1] == 'u' && input[2] == 'i' && input[3] == 't' && input[4] =='\0') return 'q';
    //���ڿ��� ó�� 4���� ��Ұ� 'q''u''i''t'�̰� ������ �ι��ڶ�� quit�� �Է��� ���̶�� �Ǵ���.
}