#include "c11serializer.h"
#include <assert.h>
#include <errno.h>

typedef struct {
	const char *name;
	serializer_t *(* please)(void);
} serializer_list_t;

static serializer_list_t serializers[] = {
	{ "binary", &binary_serializer },
	{ "text",	&text_serializer }
};

serializer_t *serializer(const char *name) {
	size_t size = sizeof(serializers) / sizeof(serializers[0]);
	for (size_t i = 0; i < size; i++)
		if (strcmp(name, serializers[i].name) == 0)
			return serializers[i].please();
	return NULL;
}

// -------------------------------------------------------------------------------------------------

int do_read(FILE *stream, void *data, size_t size, const serializer_ops_t *ops) {
	assert(ops != NULL);
	//printf("[DEBUG] reading %zu byte(s) of '%s'\n", size, ops->type_name);
	int ret = ops->read(stream, data, size);
	if (ret < 0)
		fprintf(stderr, "[ERROR] %s\n", strerror(errno));
	else if (ret != (int)size)
		fprintf(stderr, "[ERROR] read only %d byte(s) of %zu\n", ret, size);
	return ret;
}

int do_write(FILE *stream, const void *data, size_t size, const serializer_ops_t *ops) {
	assert(ops != NULL);
	//printf("[DEBUG] writing %zu byte(s) of '%s'\n", size, ops->type_name);
	int ret = ops->write(stream, data, size);
	if (ret < 0)
		fprintf(stderr, "[ERROR] %s\n", strerror(errno));
	else if (ret != (int)size)
		fprintf(stderr, "[ERROR] wrote only %d byte(s) of %zu\n", ret, size);
	return ret;
}

