#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define CREATE_STRUCT(T, NAME)	\
typedef struct {				\
	T* data;					\
	size_t len;					\
	size_t cap;					\
} NAME;

#define INIT(T1, T2)						\
void init##T2##_m(T2* arr){					\
	T1* ptr = (T1*)malloc(sizeof(T1));		\
	nullCheck(ptr);							\
	arr->data = ptr;						\
	arr->len = 0;							\
	arr->cap = 1;							\
}

#define ADD(T1, T2)														\
void add##T1##_m(T2* arr, T1 obj){										\
	arr->len++;															\
	if (arr->len >= arr->cap) {											\
		arr->cap *= 2;													\
		T1* ptr = (T1*)realloc(arr->data, arr->cap * sizeof(T1));		\
		nullCheck(ptr);													\
		arr->data = ptr;												\
	}																	\
	arr->data[arr->len - 1] = obj;										\
}

#define REMOVE(T1, T2)													\
void remove##T1##_m(T2* arr){											\
	arr->len--;															\
	if (arr->len * 2 < arr->cap) {										\
		arr->cap /= 2;													\
		T1* ptr = (T1*)realloc(arr->data, arr->cap * sizeof(T1));		\
		nullCheck(ptr);													\
		arr->data = ptr;												\
	}																	\
}

#define GET(T1, T2)								\
T1 get##T1##_m(T2* arr, int index){				\
	assert(index >= 0 && index < arr->len);		\
	return arr->data[index];					\
}

#define FREE(T)				\
void free##T##_m(T arr){	\
	free(arr.data);			\
}

void nullCheck(void* ptr) {
	if (ptr == NULL) {
		printf("Out of memory!");
		exit(0);
	}
}

CREATE_STRUCT(int, DynArray)
INIT(int, DynArray)
ADD(int, DynArray)
REMOVE(int, DynArray)
GET(int, DynArray)
FREE(DynArray)

int main(int argc, char** argv) {
	DynArray arr;
	initDynArray_m(&arr);
	addint_m(&arr, 10);
	addint_m(&arr, 2);
	removeint_m(&arr);
	addint_m(&arr, 5);
	addint_m(&arr, 10);
	removeint_m(&arr);
	printf("%d\n", getint_m(&arr, 0));
	printf("%d\n", getint_m(&arr, 1));
	freeDynArray_m(arr);
}
