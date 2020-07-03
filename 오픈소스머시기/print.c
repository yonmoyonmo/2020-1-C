#include "phone.h"
#include <stdio.h>
#pragma warning(disable:4996)
void print(void){
	if(head.next == NULL){
		printf("\n------------ Nothing is here--------------\n");
	}
	else{
		current = head.next;
		int i =0;
		for(i=0;i<size;i++){
			printf("\n[ %d ]\n",i+1);
			printf("Name : %s\n",current->Name);
			printf("Phone : %s\n",current->PhoneNumber);
			prev = current;
			current = current->next;
		}
	}
	current = prev;
}

