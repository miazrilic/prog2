#ifndef MEMORY_H
#define MEMORY_H

void* allocateMemory(size_t, size_t);
char* strDuplicate(const char*);
void deallocateMemory(bill_t*);
void freeMemory(void*);

#endif //MEMORY_H