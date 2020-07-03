#include "phone.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char password[20];
extern int checkIfRegistered;

void registerPhoneData(void){
	if(checkIfRegistered == 0){
		printf("\nYou have to set your password first\nEnter your password: ");
		scanf("%s",password); getchar();
		printf("%s is your password? [y/n] : ",password);
		char yesOrNo;
		scanf("%c",&yesOrNo); getchar();
		if(yesOrNo!='n' && yesOrNo!='y'){
			printf("invalid input, program shut down...\n");
			exit(1);
		}
		else if(yesOrNo =='n'){
			printf("please restart\n");
			exit(1);
		}
		else if(yesOrNo =='y'){
			printf("okay\n");
			checkIfRegistered = 1;
		}
	}else{
		int count = 0;
		while(1){
			if(count >=3){
				printf("you are not allowed to this\n");
				exit(1);
			}

			printf("+++>> please enter your password : ");
			char checking[20];
			scanf("%s",checking);getchar();

			if(isEqualString(password, checking) == 1)
				break;

			char* time;
			if(count == 0) time = " ";
			if(count == 1) time = "(twice)";
			if(count == 2) time =" (3 times)";
			printf("Not Matched %s !!!\n",time);
			count++;
		}
	}
	printf("\n_______ADD NEW CONTACT_______\n");
	char _name[10];
	char _phoneNumber[13];
	printf("NAME : "); scanf("%s",_name);
	printf("PHONE : "); scanf("%s",_phoneNumber);
	if(head.next == NULL){
		head.next = (Contact*)malloc(sizeof(Contact));
		strcpy(head.next->Name,_name);
		strcpy(head.next->PhoneNumber,_phoneNumber);
		current = head.next;
		current->next = NULL;
		size++;
	}else{
		current->next = (Contact*)malloc(sizeof(Contact));
		strcpy(current->next->Name, _name);
		strcpy(current->next->PhoneNumber,_phoneNumber);
		current = current->next;
		current->next = NULL;
		size++;
	}
}
