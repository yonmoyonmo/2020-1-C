#include <stdio.h>
#include <string.h>

void enterString(char* input); //문자열을 입력받는 함수
void printProcessedString(char* input, char* output); //문자열을 처리하는 함수
char checkString(char* input);//문자열을 검사해서 , . quit을 찾아내는 함수
void myStrtok(char* input, const char cutter, char* beforeCutter, char* afterCutter); 
//strtok_s함수가 안되서 직접만든 야매 strtok

int main() {
    char input[200]=" ";
    //문자열을 입력받아 저장할 변수
    char output[200]=" ";
    //입력 받은 문자열을 처리한 후 최종 결과가 될 문자열을 저장할 변수
    
    while (1){
        enterString(input);//문자열을 입력받는다.
        printProcessedString(input, output);//문자열을 처리한다.
        if (checkString(input) == 'q') return 0;//만약에 quit이 단독으로 입력되었다면 프로그램을 종료한다.
    }

    return 0;
}

void enterString(char* input) {
    //입력부를 함수로 떼어 놓아야 속이 편하다.
    printf("문장을 입력하세요. > ");
    gets(input);
}

void printProcessedString(char* input, char* output) {
    char beforeCutter[200]; //구분문자 이전의 문자열을 저장할 변수
    char afterCutter[200]; //구분문자 이후의 문자열을 저장할 변수
    char cutter; //구분문자가 될 변수

    if (checkString(input) == ',') { //문자열 중 ','이 있는 경우
        cutter = ','; //구분문자를 ','로 설정하고
        myStrtok(input, cutter, beforeCutter, afterCutter); 
        //문자열을 구분문자 기준으로 문자열을 반띵해주는 함수에 집어넣는다.
        strcpy_s(output,200,afterCutter);
        //반띵한 문자열 중 구분문자 뒷부분을 최종 결과물이 될 문자열에 복사한다.
        strcat_s(output, 200, ", ");
        //문자열을 나누다가 사라진 ',' 도 추가해준다.
        strcat_s(output, 200, beforeCutter);
        //최종 결과물 문자열에 반띵한 앞부분을 붙여준다.
        printf("결과문장\n%s\n",output);
    }
    else if (checkString(input) == '.') {//문자열 중 '.'이 있는 경우
        cutter = '.'; //구분문자를 설정한다.
        myStrtok(input, cutter, beforeCutter, afterCutter);
        //구분문자를 기준으로 반으로 나눈다.
        strcpy_s(output,200, beforeCutter);
        //반으로 나눈 앞부분을 먼저 복사한다.
        strcat_s(output, 200, " \n");
        //개행문자를 넣어준다.
        strcat_s(output, 200, afterCutter);
        //뒷부분을 붙인다.
        printf("결과문장\n%s\n", output);
    }
    else printf("%s\n", input);
}

void myStrtok(char* input, const char cutter, char* beforeCutter, char* afterCutter) {
    /****************************************************************
    char* strtok_s(char* str, const char* delimiters, char** context)
    함수를 쓰려고 했는데 올바로 사용해도 엑세스위반이 계속 일어나서
    분명히 나의 실수일거라 생각하며 열심히 디버깅을 했지만
    현재 나의 수준으로 원인을 찾을 수 없었으므로
    과제를 위한 야매 strtok를 구현했다.
    이름만 strtok이고 쓰임새는 한정적이다.
    자를 문자열 하나, 구분문자 하나, 빈 문자열 둘을 넘기면
    구분문자 하나를 기준으로 앞 뒤로 문자열을 나눠서 저장해준다.
    *****************************************************************/
    
    int i = 0; //구분문자의 위치 인덱스를 나타낼 변수이다.
    while (input[i] != '\0') {
        if (input[i] == cutter) {
            break;
        }//구분문자를 만나면 루프를 빠져나간다.
        ++i;
    } //이제 i는 input에서 구분문자가 있는 위치의 인덱스를 나타낸다.
    int j = 0;
    for (j = 0; j < i; j++) { 
        //input에서 i전까지(구분문자 전) 복사해서 저장
        beforeCutter[j] = input[j];
        beforeCutter[j + 1] = '\0'; //널문자 넣어야 문자열이 된다.
    }

    j = 0;
    while (input[i] != '\0') {
        //구분문자+1부터 끝까지 복사해서 저장함  
        afterCutter[j] = input[i+1];
        ++i;
        ++j;
    } 
    afterCutter[j + 1] = '\0';//마찬가지로 널문자를 넣어준다.
}


char checkString(char* input) {
    //문자열에 ',' '.' "quit"을 확인하는 함수
    //찾은 문자를 리턴한다.
    int length = strlen(input);
    int i = 0;
    for (i = 0; i < length; i++) {
        if (input[i] == ',') return ',';
        if (input[i] == '.') return '.';
    }
    if (input[0] == 'q' && input[1] == 'u' && input[2] == 'i' && input[3] == 't' && input[4] =='\0') return 'q';
    //문자열의 처음 4개의 요소가 'q''u''i''t'이고 다음이 널문자라면 quit를 입력한 것이라고 판단함.
}