#pragma once

#include "types.h"

c11serializer_serializer_t *c11serializer_text_serializer(void);

#define c11serializer_text_serializer_ops_for(x)													\
	_Generic((x), 																					\
		/*void:						&c11serializer_text_serializer_ops_for_void,*/					\
		/*const void:				&c11serializer_text_serializer_ops_for_constvoid,*/				\
		char:						&c11serializer_text_serializer_ops_for_char,					\
		const char:					&c11serializer_text_serializer_ops_for_constchar,				\
		signed char:				&c11serializer_text_serializer_ops_for_signedchar,				\
		const signed char:			&c11serializer_text_serializer_ops_for_constsignedchar,			\
		unsigned char:				&c11serializer_text_serializer_ops_for_unsignedchar,			\
		const unsigned char:		&c11serializer_text_serializer_ops_for_constunsignedchar,		\
		short:						&c11serializer_text_serializer_ops_for_short,					\
		const short:				&c11serializer_text_serializer_ops_for_constshort,				\
		unsigned short:				&c11serializer_text_serializer_ops_for_unsignedshort,			\
		const unsigned short:		&c11serializer_text_serializer_ops_for_constunsignedshort,		\
		int:						&c11serializer_text_serializer_ops_for_int,						\
		const int:					&c11serializer_text_serializer_ops_for_constint,				\
		unsigned int:				&c11serializer_text_serializer_ops_for_unsignedint,				\
		const unsigned int:			&c11serializer_text_serializer_ops_for_constunsignedint,		\
		long:						&c11serializer_text_serializer_ops_for_long,					\
		const long:					&c11serializer_text_serializer_ops_for_constlong,				\
		unsigned long:				&c11serializer_text_serializer_ops_for_unsignedlong,			\
		const unsigned long:		&c11serializer_text_serializer_ops_for_constunsignedlong,		\
		long long:					&c11serializer_text_serializer_ops_for_longlong,				\
		const long long:			&c11serializer_text_serializer_ops_for_constlonglong,			\
		unsigned long long:			&c11serializer_text_serializer_ops_for_unsignedlonglong,		\
		const unsigned long long:	&c11serializer_text_serializer_ops_for_constunsignedlonglong,	\
		double:						&c11serializer_text_serializer_ops_for_double,					\
		const double:				&c11serializer_text_serializer_ops_for_constdouble,				\
		long double:				&c11serializer_text_serializer_ops_for_longdouble,				\
		const long double:			&c11serializer_text_serializer_ops_for_constlongdouble,			\
		float:					 	&c11serializer_text_serializer_ops_for_float,					\
		const float:				&c11serializer_text_serializer_ops_for_constfloat,				\
	    default:					NULL															\
	)

//extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_void;
//extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constvoid;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_char;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constchar;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_signedchar;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constsignedchar;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_unsignedchar;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constunsignedchar;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_short;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constshort;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_unsignedshort;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constunsignedshort;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_int;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constint;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_unsignedint;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constunsignedint;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_long;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constlong;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_unsignedlong;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constunsignedlong;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_longlong;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constlonglong;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_unsignedlonglong;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constunsignedlonglong;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_double;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constdouble;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_longdouble;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constlongdouble;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_float;
extern c11serializer_serializer_ops_t c11serializer_text_serializer_ops_for_constfloat;
