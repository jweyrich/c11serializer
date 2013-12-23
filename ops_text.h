#pragma once

#include "types.h"

serializer_t *text_serializer(void);

#define text_serializer_ops_for(x)													\
	_Generic((x), 																	\
		/*void:						&text_serializer_ops_for_void,*/				\
		/*const void:				&text_serializer_ops_for_constvoid,*/			\
		char:						&text_serializer_ops_for_char,					\
		const char:					&text_serializer_ops_for_constchar,				\
		signed char:				&text_serializer_ops_for_signedchar,			\
		const signed char:			&text_serializer_ops_for_constsignedchar,		\
		unsigned char:				&text_serializer_ops_for_unsignedchar,			\
		const unsigned char:		&text_serializer_ops_for_constunsignedchar,		\
		short:						&text_serializer_ops_for_short,					\
		const short:				&text_serializer_ops_for_constshort,			\
		unsigned short:				&text_serializer_ops_for_unsignedshort,			\
		const unsigned short:		&text_serializer_ops_for_constunsignedshort,	\
		int:						&text_serializer_ops_for_int,					\
		const int:					&text_serializer_ops_for_constint,				\
		unsigned int:				&text_serializer_ops_for_unsignedint,			\
		const unsigned int:			&text_serializer_ops_for_constunsignedint,		\
		long:						&text_serializer_ops_for_long,					\
		const long:					&text_serializer_ops_for_constlong,				\
		unsigned long:				&text_serializer_ops_for_unsignedlong,			\
		const unsigned long:		&text_serializer_ops_for_constunsignedlong,		\
		long long:					&text_serializer_ops_for_longlong,				\
		const long long:			&text_serializer_ops_for_constlonglong,			\
		unsigned long long:			&text_serializer_ops_for_unsignedlonglong,		\
		const unsigned long long:	&text_serializer_ops_for_constunsignedlonglong,	\
		double:						&text_serializer_ops_for_double,				\
		const double:				&text_serializer_ops_for_constdouble,			\
		long double:				&text_serializer_ops_for_longdouble,			\
		const long double:			&text_serializer_ops_for_constlongdouble,		\
		float:					 	&text_serializer_ops_for_float,					\
		const float:				&text_serializer_ops_for_constfloat,			\
	    default:					NULL											\
	)

//extern serializer_ops_t text_serializer_ops_for_void;
//extern serializer_ops_t text_serializer_ops_for_constvoid;
extern serializer_ops_t text_serializer_ops_for_char;
extern serializer_ops_t text_serializer_ops_for_constchar;
extern serializer_ops_t text_serializer_ops_for_signedchar;
extern serializer_ops_t text_serializer_ops_for_constsignedchar;
extern serializer_ops_t text_serializer_ops_for_unsignedchar;
extern serializer_ops_t text_serializer_ops_for_constunsignedchar;
extern serializer_ops_t text_serializer_ops_for_short;
extern serializer_ops_t text_serializer_ops_for_constshort;
extern serializer_ops_t text_serializer_ops_for_unsignedshort;
extern serializer_ops_t text_serializer_ops_for_constunsignedshort;
extern serializer_ops_t text_serializer_ops_for_int;
extern serializer_ops_t text_serializer_ops_for_constint;
extern serializer_ops_t text_serializer_ops_for_unsignedint;
extern serializer_ops_t text_serializer_ops_for_constunsignedint;
extern serializer_ops_t text_serializer_ops_for_long;
extern serializer_ops_t text_serializer_ops_for_constlong;
extern serializer_ops_t text_serializer_ops_for_unsignedlong;
extern serializer_ops_t text_serializer_ops_for_constunsignedlong;
extern serializer_ops_t text_serializer_ops_for_longlong;
extern serializer_ops_t text_serializer_ops_for_constlonglong;
extern serializer_ops_t text_serializer_ops_for_unsignedlonglong;
extern serializer_ops_t text_serializer_ops_for_constunsignedlonglong;
extern serializer_ops_t text_serializer_ops_for_double;
extern serializer_ops_t text_serializer_ops_for_constdouble;
extern serializer_ops_t text_serializer_ops_for_longdouble;
extern serializer_ops_t text_serializer_ops_for_constlongdouble;
extern serializer_ops_t text_serializer_ops_for_float;
extern serializer_ops_t text_serializer_ops_for_constfloat;
