#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct student {
	char* firstName;
	char* lastName;
	int id;
	struct student* nextStudent;
}STUDENT;

STUDENT* createStudentList(void);
STUDENT* insertStudentToList(STUDENT*);
int printStudentList(STUDENT*);
STUDENT* searchStudent(STUDENT*, int);
int deleteStudentFromList(STUDENT**, STUDENT*);
STUDENT* deleteWholeStudentList(STUDENT*);

#endif //FUNCTIONS_H