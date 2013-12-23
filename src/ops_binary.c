#include "ops_binary.h"
#include <assert.h>
#include <stdio.h>

#define SERIALIZER_NAME											binary
#define SERIALIZER_OPS_PREFIX									PASTE(c11serializer_, SERIALIZER_NAME, _serializer_ops_for_)

#define DEFINE_SERIALIZER_OPS_FOR_TYPE1(T1)						DEFINE_SERIALIZER_OPS_FOR_TYPE_(1,T1,,,,,)
#define DEFINE_SERIALIZER_OPS_FOR_TYPE2(T1,T2) 					DEFINE_SERIALIZER_OPS_FOR_TYPE_(2,T1,T2,,,,)
#define DEFINE_SERIALIZER_OPS_FOR_TYPE3(T1,T2,T3)				DEFINE_SERIALIZER_OPS_FOR_TYPE_(3,T1,T2,T3,,,)
#define DEFINE_SERIALIZER_OPS_FOR_TYPE4(T1,T2,T3,T4)			DEFINE_SERIALIZER_OPS_FOR_TYPE_(4,T1,T2,T3,T4,,)
#define DEFINE_SERIALIZER_OPS_FOR_TYPE5(T1,T2,T3,T4,T5)			DEFINE_SERIALIZER_OPS_FOR_TYPE_(5,T1,T2,T3,T4,T5,)
#define DEFINE_SERIALIZER_OPS_FOR_TYPE6(T1,T2,T3,T4,T5,T6)		DEFINE_SERIALIZER_OPS_FOR_TYPE_(6,T1,T2,T3,T4,T5,T6)
#define DEFINE_SERIALIZER_OPS_FOR_TYPE_(N,T1,T2,T3,T4,T5,T6)							\
	int PASTE(SERIALIZER_NAME,_read_,T1,T2,T3,T4,T5,T6)									\
		(FILE *stream, void *data, size_t size)											\
	{																					\
		assert(stream != NULL);															\
		assert(size > 0);																\
		size_t ret = fread(data, size, 1, stream);										\
		return ret == 1 ? size : -1;													\
	}																					\
	int PASTE(SERIALIZER_NAME,_write_,T1,T2,T3,T4,T5,T6)								\
		(FILE *stream, const void *data, size_t size)									\
	{																					\
		assert(stream != NULL);															\
		assert(size > 0);																\
		size_t ret = fwrite(data, size,  1, stream);									\
		return ret == 1 ? size : -1;													\
	}																					\
	c11serializer_serializer_ops_t PASTE(SERIALIZER_OPS_PREFIX,T1,T2,T3,T4,T5,T6) = {	\
		.type_name = C11SERIALIZER_SERIALIZER_OPS_TYPE_NAME(N,T1,T2,T3,T4,T5,T6),		\
		.read = &PASTE(SERIALIZER_NAME,_read_,T1,T2,T3,T4,T5,T6),						\
		.write = &PASTE(SERIALIZER_NAME,_write_,T1,T2,T3,T4,T5,T6)						\
	}

//DEFINE_SERIALIZER_OPS_FOR_TYPE1(void);
//DEFINE_SERIALIZER_OPS_FOR_TYPE1(const, void);
DEFINE_SERIALIZER_OPS_FOR_TYPE1(char);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(const, char);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(signed, char);
DEFINE_SERIALIZER_OPS_FOR_TYPE3(const, signed, char);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(unsigned, char);
DEFINE_SERIALIZER_OPS_FOR_TYPE3(const, unsigned, char);
DEFINE_SERIALIZER_OPS_FOR_TYPE1(short);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(const, short);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(unsigned, short);
DEFINE_SERIALIZER_OPS_FOR_TYPE3(const, unsigned, short);
DEFINE_SERIALIZER_OPS_FOR_TYPE1(int);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(const, int);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(unsigned, int);
DEFINE_SERIALIZER_OPS_FOR_TYPE3(const, unsigned, int);
DEFINE_SERIALIZER_OPS_FOR_TYPE1(long);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(const, long);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(unsigned, long);
DEFINE_SERIALIZER_OPS_FOR_TYPE3(const, unsigned, long);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(long, long);
DEFINE_SERIALIZER_OPS_FOR_TYPE3(const, long, long);
DEFINE_SERIALIZER_OPS_FOR_TYPE3(unsigned, long, long);
DEFINE_SERIALIZER_OPS_FOR_TYPE4(const, unsigned, long, long);
DEFINE_SERIALIZER_OPS_FOR_TYPE1(double);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(const, double);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(long, double);
DEFINE_SERIALIZER_OPS_FOR_TYPE3(const, long, double);
DEFINE_SERIALIZER_OPS_FOR_TYPE1(float);
DEFINE_SERIALIZER_OPS_FOR_TYPE2(const, float);

c11serializer_serializer_t *c11serializer_binary_serializer(void) {
	return NULL;
}

