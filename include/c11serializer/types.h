#pragma once

#include <stddef.h>
#include <stdio.h>

typedef struct {
	const char *type_name;
	int (* read)(FILE *stream, void *data, size_t size);
	int (* write)(FILE *stream, const void *data, size_t size);
} serializer_ops_t;

typedef struct {
	const char *name;
	serializer_ops_t *ops;
} serializer_t;

#define is_compatible(x, T)	_Generic((x), T: true, default: false)

// Stringify
#define HASH(_1)											#_1
#define STR(_1)												HASH(_1)

// Concatenation
#define PASTE(...)											PASTE_(0,__VA_ARGS__)
#define PASTE_(...)											PASTE_N(__VA_ARGS__,10,9,8,7,6,5,4,3,2,1,0)
#define PASTE_N(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,N,...)	PASTE_ ## N (_1,_2,_3,_4,_5,_6,_7,_8,_9,_10)
#define PASTE_0(...)
#define PASTE_1(_1,...)										_1
#define PASTE_2(_1,_2,...)									_1 ## _2
#define PASTE_3(_1,_2,_3,...)								_1 ## _2 ## _3
#define PASTE_4(_1,_2,_3,_4,...)							_1 ## _2 ## _3 ## _4
#define PASTE_5(_1,_2,_3,_4,_5,...)							_1 ## _2 ## _3 ## _4 ## _5
#define PASTE_6(_1,_2,_3,_4,_5,_6,...)						_1 ## _2 ## _3 ## _4 ## _5 ## _6
#define PASTE_7(_1,_2,_3,_4,_5,_6,_7,...)					_1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7
#define PASTE_7(_1,_2,_3,_4,_5,_6,_7,...)					_1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7
#define PASTE_8(_1,_2,_3,_4,_5,_6,_7,_8,...)				_1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8
#define PASTE_9(_1,_2,_3,_4,_5,_6,_7,_8,_9,...)				_1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9
#define PASTE_10(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,...)		_1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10

#define SERIALIZER_OPS_TYPE_NAME(N,...)						SERIALIZER_OPS_TYPE_NAME_ ## N (__VA_ARGS__)
#define SERIALIZER_OPS_TYPE_NAME_0(...)						"<missing type>"
#define SERIALIZER_OPS_TYPE_NAME_1(_1,...)					STR(_1)
#define SERIALIZER_OPS_TYPE_NAME_2(_1,_2,...)				STR(_1) " " STR(_2)
#define SERIALIZER_OPS_TYPE_NAME_3(_1,_2,_3,...)			STR(_1) SERIALIZER_OPS_TYPE_NAME_2(_2,_3,)
#define SERIALIZER_OPS_TYPE_NAME_4(_1,_2,_3,_4,...)			STR(_1) SERIALIZER_OPS_TYPE_NAME_3(_2,_3,_4,)
#define SERIALIZER_OPS_TYPE_NAME_5(_1,_2,_3,_4,_5,...)		STR(_1) SERIALIZER_OPS_TYPE_NAME_4(_2,_3,_4,_5,)
