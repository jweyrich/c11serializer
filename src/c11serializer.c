#include "c11serializer.h"
#include <assert.h>
#include <errno.h>

#if 1
typedef struct {
	const char *name;
	c11serializer_serializer_t *(* please)(void);
} c11serializer_serializer_list_t;

static c11serializer_serializer_list_t available_serializers[] = {
	{ "binary", &c11serializer_binary_serializer },
	{ "text",	&c11serializer_text_serializer }
};

static c11serializer_serializer_t *c11serializer_serializer_by_name(const char *name) {
	size_t size = sizeof(available_serializers) / sizeof(available_serializers[0]);
	for (size_t i = 0; i < size; i++)
		if (strcmp(name, available_serializers[i].name) == 0)
			return available_serializers[i].please();
	return NULL;
}
#endif

// -------------------------------------------------------------------------------------------------

int c11serializer_do_read(FILE *stream, void *data, size_t size, const c11serializer_serializer_ops_t *ops) {
	assert(ops != NULL);
	//printf("[DEBUG] reading %zu byte(s) of '%s'\n", size, ops->type_name);
	int ret = ops->read(stream, data, size);
	if (ret < 0)
		fprintf(stderr, "[ERROR] %s\n", strerror(errno));
	else if (ret != (int)size)
		fprintf(stderr, "[ERROR] read only %d byte(s) of %zu\n", ret, size);
	return ret;
}

int c11serializer_do_write(FILE *stream, const void *data, size_t size, const c11serializer_serializer_ops_t *ops) {
	assert(ops != NULL);
	//printf("[DEBUG] writing %zu byte(s) of '%s'\n", size, ops->type_name);
	int ret = ops->write(stream, data, size);
	if (ret < 0)
		fprintf(stderr, "[ERROR] %s\n", strerror(errno));
	else if (ret != (int)size)
		fprintf(stderr, "[ERROR] wrote only %d byte(s) of %zu\n", ret, size);
	return ret;
}

