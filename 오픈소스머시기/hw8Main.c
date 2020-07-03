#include <stdio.h>
#include <stdlib.h>
#include "phone.h"

void (*pFuncs[5])() = { registerPhoneData, print, searchByName, deleteByName, sort };
int size = 0;
char password[20];
int checkIfRegistered = 0;
static int count_service = 0;
Contact head;
Contact* current;
Contact* prev;
FILE* savefile;
FILE* loadfile;


int isEqualString(char* a, char* b){
	int i =0;
	for(i =0; a[i]!='\0';i++)
		;

	int j = 0;
	for(j=0; b[j]!='\0';j++)
		;

	int k = 0;
	if(i == j){
		for(k=0;k<i;k++){
			if(a[k] != b[k]) return 0;
		}
		return 1;
	}
	else return 0;
}

void save(){
	printf("save start\n");
	savefile = fopen("phone.dat","wb");
	if(savefile == NULL){
		printf("file open fail\n");
		return;
	}
	current = head.next;
	if(current == NULL){
		return;
	}
	int i = 0;
	for(i = 0;i<size;i++){
		fwrite(current, sizeof(Contact),1, savefile);
		current = current->next;
		if(current == NULL) break;
	}
	fclose(savefile);
	printf("save completed\n");
}

void load(){
	printf("load start\n");
	loadfile = fopen("phone.dat","rb");
	if(loadfile == NULL){
		printf("there is no saved data\n");
		return;
	}
	while(1){
		Contact* temp = (Contact*)malloc(sizeof(Contact));
		int check = fread(temp,sizeof(Contact),1,loadfile);
		if (check == 0) {
			break;
		}
		if (head.next == NULL) {
			head.next = temp;
			current = head.next;
			size++;
		}
		else {
			current->next = temp;
			prev = current;
			current = current->next;
			size++;
		}
	}
	current = prev;
	fclose(loadfile);
	printf("load completed\n");
}

int main()
{
	head.next = NULL;
	current = NULL;

	load();

	int service;
	do
	{
        printf("============ Telephone Book Management ============");
        printf("\n <<<1. Register\t2. Print All \t 3.Search by ID \t4. Delete \t5. sort \t6. Exit >>>\n");
        printf(" Please enter your service number (1-6)> ");
		scanf("%d", &service);
		if ( service > 0 && service <= 5 )
		{
			pFuncs[service-1]();
			count_service++;
		}
		else if( service ==0 || service > 6)
		{
			printf("You choose a wrong service number\n");
		}
	} while (service != 6);

	printf("saving data....\n");
	save();
	return 0;
}

