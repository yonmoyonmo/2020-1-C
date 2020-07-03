// array of sturcure
#ifndef PHONE
#define PHONE

typedef struct contact_st
{
    char Name[10];
    char PhoneNumber[13];
    struct contact_st *next;
} Contact;

extern int size;  // store the actual numbers of PhoneBook

extern char password[20];

extern Contact head;
extern Contact* current;
extern Contact* prev;

void registerPhoneData();
void print();
void searchByName();
void deleteByName();
void sort();
int isEqualString(char* a, char* b);
void save();
void load();

#endif

