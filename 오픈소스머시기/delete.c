#include "phone.h"
#include <stdio.h>
#include <stdlib.h>

void deleteByName(void){
	Contact* deleteHelper;
	Contact* linkingHelper;

	current = head.next;
	linkingHelper = &head;
	char _name[10];
	printf("=> Enter a name for deleting : ");
	scanf("%s", _name);
	int i = 0;
	for(i=0;isEqualString(current->Name, _name)!=1; i++){
		if(current->next != NULL){
			linkingHelper = linkingHelper->next;
			current = current->next;
		}
		if(i>=size) break;
	}
	if(i>=size){
		printf("\n ooooooopssssssss %s is not in this phonebook\n\n",_name);
	}else{
		deleteHelper = current;
		current = current->next;
		linkingHelper->next = current;
		free(deleteHelper);
		size--;
		printf("\n***** %s is deleted *****\n",_name);
	}
}

