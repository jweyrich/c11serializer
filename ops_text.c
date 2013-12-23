#include "ops_text.h"
#include <assert.h>
#include <float.h>
#include <stdio.h>

#define SERIALIZER_NAME										text
#define SERIALIZER_OPS_PREFIX								PASTE(SERIALIZER_NAME, _serializer_ops_for_)

#define DEFINE_SERIALIZER_OPS_FOR_TYPE1(T1)					DEFINE_SERIALIZER_OPS_FOR_TYPE_(1,T1,,,,,)
#define DEFINE_SERIALIZER_OPS_FOR_TYPE2(T1,T2) 				DEFINE_SERIALIZER_OPS_FOR_TYPE_(2,T1,T2,,,,)
#define DEFINE_SERIALIZER_OPS_FOR_TYPE3(T1,T2,T3)			DEFINE_SERIALIZER_OPS_FOR_TYPE_(3,T1,T2,T3,,,)
#define DEFINE_SERIALIZER_OPS_FOR_TYPE4(T1,T2,T3,T4)		DEFINE_SERIALIZER_OPS_FOR_TYPE_(4,T1,T2,T3,T4,,)
#define DEFINE_SERIALIZER_OPS_FOR_TYPE5(T1,T2,T3,T4,T5)		DEFINE_SERIALIZER_OPS_FOR_TYPE_(5,T1,T2,T3,T4,T5,)
#define DEFINE_SERIALIZER_OPS_FOR_TYPE6(T1,T2,T3,T4,T5,T6)	DEFINE_SERIALIZER_OPS_FOR_TYPE_(6,T1,T2,T3,T4,T5,T6)

#define DEFINE_SERIALIZER_OPS_FOR_TYPE_(N,T1,T2,T3,T4,T5,T6)										\
	int PASTE(SERIALIZER_NAME,_read_,T1,T2,T3,T4,T5,T6)												\
		(FILE *stream, void *data, size_t size)														\
	{																								\
		assert(stream != NULL);																		\
		assert(size > 0);																			\
		T1 T2 T3 T4 T5 T6 *foo = NULL;																\
		/*																							\
		printf("[DEBUG] the format specifier for '%s' is '%s'\n", 									\
			STR(PASTE(T1,T2,T3,T4,T5,T6)),															\
			format_specifier_for_read(foo));														\
		*/																							\
		int ret = fscanf(stream, format_specifier_for_read(foo), (T1 T2 T3 T4 T5 T6 *)data);		\
		return ret == 1 ? size : -1;																\
	}																								\
	int PASTE(SERIALIZER_NAME,_write_,T1,T2,T3,T4,T5,T6)											\
		(FILE *stream, const void *data, size_t size)												\
	{																								\
		assert(stream != NULL);																		\
		assert(size > 0);																			\
		T1 T2 T3 T4 T5 T6 *foo = NULL;																\
		int ret = fprintf(stream, format_specifier_for_write(foo), *((T1 T2 T3 T4 T5 T6 *)data));	\
		return ret > 0 ? size : -1;																	\
	}																								\
	serializer_ops_t PASTE(SERIALIZER_OPS_PREFIX,T1,T2,T3,T4,T5,T6) = {								\
		.type_name = SERIALIZER_OPS_TYPE_NAME(N,T1,T2,T3,T4,T5,T6),									\
		.read = &PASTE(SERIALIZER_NAME,_read_,T1,T2,T3,T4,T5,T6),									\
		.write = &PASTE(SERIALIZER_NAME,_write_,T1,T2,T3,T4,T5,T6)									\
	}

#define format_specifier_for_read(x)								\
	_Generic((x), 													\
		const void *:				NULL,							\
		const char *:				NULL,							\
		const signed char *:		NULL,							\
		const unsigned char *:		NULL,							\
		const short *:				NULL,							\
		const unsigned short *:		NULL,							\
		const int *:				NULL,							\
		const unsigned int *:		NULL,							\
		const long *:				NULL,							\
		const unsigned long *:		NULL,							\
		const long long *:			NULL,							\
		const unsigned long long *:	NULL,							\
		const double *:				NULL,							\
		const long double *:		NULL,							\
		const float *:				NULL,							\
		default:					format_specifier_for_write(x)	\
	)

#define format_specifier_for_write(x)								\
	_Generic((x), 													\
		void *:							"%p",						\
		const void *:					"%p",						\
		char *:							"%c",						\
		const char *:					"%c",						\
		signed char *:					"%hhi",						\
		const signed char *:			"%hhi",						\
		unsigned char *:				"%hhu",						\
		const unsigned char *:			"%hhu",						\
		short *:						"%hi",						\
		const short *:					"%hi",						\
		unsigned short *:				"%hu",						\
		const unsigned short *:			"%hu",						\
		int *:							"%i",						\
		const int *:					"%i",						\
		unsigned int *:					"%u",						\
		const unsigned int *:			"%u",						\
		long *:							"%li",						\
		const long *:					"%li",						\
		unsigned long *:				"%lu",						\
		const unsigned long *:			"%lu",						\
		long long *:					"%lli",						\
		const long long *:				"%lli",						\
		unsigned long long *:			"%llu",						\
		const unsigned long long *:		"%llu",						\
		/*															\
		double *:						"%." STR(DBL_DIG)	"lf",	\
		const double *:					"%." STR(DBL_DIG)	"lf",	\
		long double *:					"%." STR(LDBL_DIG)	"Lf",	\
		const long double *:			"%." STR(LDBL_DIG)	"Lf",	\
		float *:						"%." STR(FLT_DIG)	"f",	\
		const float *:					"%." STR(FLT_DIG)	"f",	\
		*/															\
		double *:						"%la",						\
		const double *:					"%la",						\
		long double *:					"%La",						\
		const long double *:			"%La",						\
		float *:						"%a",						\
		const float *:					"%a",						\
		default:						NULL						\
	)

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

serializer_t *text_serializer(void) {
	return NULL;
}
