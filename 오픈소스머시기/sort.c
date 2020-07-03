#include "phone.h"
#include <stdio.h>
#include <string.h>

void sort(void){
	if(head.next == NULL){
		printf("EMPTY LIST------------------\n");
		return;
	}

	printf("\tBefore___________________________\n");
	print();

	printf("\tAfter sorting______________________________\n");

	current = head.next;
	if(current->next != NULL){
		Contact* sortHelper;
		int i = 0;
		for(i = 0; i<size; i++){
			current = head.next;
			while(current->next != NULL){
				sortHelper = current->next;
				if(strcmp(current->Name, sortHelper->Name) > 0){
					char tempName[10];
					char tempNumber[13];
					strcpy(tempName, sortHelper->Name);
					strcpy(tempNumber, sortHelper->PhoneNumber);
					strcpy(sortHelper->Name, current->Name);
					strcpy(sortHelper->PhoneNumber, current->PhoneNumber);
					strcpy(current->Name, tempName);
					strcpy(current->PhoneNumber, tempNumber);	
				}
				current = sortHelper;
			}
		}
		
		print();	
		return;	
	}else print();
}


		
