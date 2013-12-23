#pragma once

#include <stdio.h>
#include <string.h>

#include "ops_binary.h"
#include "ops_text.h"

#define serialize(stream, v, format) \
	c11serializer_do_write(stream, &v, sizeof((v)), c11serializer_ ## format ## _serializer_ops_for(v));
#define serialize_appending_a_char(stream, v, format, the_char) \
	{ \
		int _ret = serialize(stream, v, format); \
		size_t size = sizeof((v)); \
		if (_ret < 0 || _ret != (int)size) { \
			; \
		} else { \
			_ret = fprintf(stream, "%c", the_char); \
		} \
		_ret; \
	}
#define serialize_appending_whitespace(stream, v, format)	serialize_appending_a_char(stream, v, format, ' ')
#define serialize_appending_newline(stream, v, format)		serialize_appending_a_char(stream, v, format, '\n')

#define deserialize(stream, v, format) \
	c11serializer_do_read(stream, &v, sizeof((v)), c11serializer_ ## format ## _serializer_ops_for(v));
#define deserialize_skipping_a_char(stream, v, format) \
	{ \
		int _ret = deserialize(stream, v, format); \
		size_t size = sizeof((v)); \
		if (_ret < 0 || _ret != (int)size) { \
			; \
		} else { \
			char skip_char; \
			_ret = fscanf(stream, "%c", &skip_char); \
		} \
		_ret; \
	}
#define deserialize_skipping_whitespace(stream, v, format)	deserialize_skipping_a_char(stream, v, format)
#define deserialize_skipping_newline(stream, v, format)		deserialize_skipping_a_char(stream, v, format)

int c11serializer_do_write(FILE *stream, const void *data, size_t size, const c11serializer_serializer_ops_t *ops);
int c11serializer_do_read(FILE *stream, void *data, size_t size, const c11serializer_serializer_ops_t *ops);
