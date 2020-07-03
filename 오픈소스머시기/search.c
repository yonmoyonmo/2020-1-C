#include "phone.h"
#include <stdio.h>

void searchByName(void){
	current = head.next;
	char _name[10];
	printf("=> Enter a name for searching : ");
	scanf("%s", _name);
	int i = 0;
	for(i=0;isEqualString(current->Name, _name)!=1; i++){
		if(current->next != NULL)
			current = current->next;
		if(i>=size) break;
	}
	if(i>=size){
		printf("\n ooooooopssssssss %s is not in this phonebook\n\n",_name);
	}else{
		printf("\n@@@ Search result: %s\t%s\n\n", current->Name, current->PhoneNumber);
	}
}

