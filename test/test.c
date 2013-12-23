#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "c11serializer.h"

struct example1 {
	int i;
	unsigned int ui;
	char c;
	float f;
	double d;
	long double ld;
	const long cl;
};

int test_binary(void) {
	FILE *file = NULL;

	const long double PI = 3.14159265358979323846L;
	struct example1 ex1 = {
		.i = INT_MAX,
		.ui = UINT_MAX,
		.c = 'a',
		.f = PI,
		.d = PI,
		.ld = PI,
		.cl = 987654321
	};

	file = fopen("data.bin", "w");
	if (file == NULL) {
		fprintf(stderr, "Error: %s\n", strerror(errno));
		return -1;
	}
	printf("-> Writing file\n");
	serialize(file, ex1.i,  binary);
	serialize(file, ex1.ui, binary);
	serialize(file, ex1.c,  binary);
	serialize(file, ex1.f,  binary);
	serialize(file, ex1.d,  binary);
	serialize(file, ex1.ld, binary);
	serialize(file, ex1.cl, binary);
	fclose(file);

	file = fopen("data.bin", "r");
	if (file == NULL) {
		fprintf(stderr, "Error: %s\n", strerror(errno));
		return -1;
	}
	printf("-> Reading file\n");
	memset(&ex1, 0, sizeof(ex1));
	deserialize(file, ex1.i,  binary);
	deserialize(file, ex1.ui, binary);
	deserialize(file, ex1.c,  binary);
	deserialize(file, ex1.f,  binary);
	deserialize(file, ex1.d,  binary);
	deserialize(file, ex1.ld, binary);
	//deserialize(file, ex1.cl, binary);
	fclose(file);

	printf("-> Result\n");
	serialize_appending_newline(stdout, ex1.i,  text);
	serialize_appending_newline(stdout, ex1.ui, text);
	serialize_appending_newline(stdout, ex1.c,  text);
	serialize_appending_newline(stdout, ex1.f,  text);
	serialize_appending_newline(stdout, ex1.d,  text);
	serialize_appending_newline(stdout, ex1.ld, text);
	serialize_appending_newline(stdout, ex1.cl, text);

	return 0;
}

int test_text(void) {
	FILE *file = NULL;

	const long double PI = 3.14159265358979323846L;
	struct example1 ex1 = {
		.i = INT_MAX,
		.ui = UINT_MAX,
		.c = 'a',
		.f = PI,
		.d = PI,
		.ld = PI,
		.cl = 987654321
	};

	file = fopen("data.txt", "w");
	if (file == NULL) {
		fprintf(stderr, "Error: %s\n", strerror(errno));
		return -1;
	}
	printf("-> Writing file\n");
	serialize_appending_newline(file, ex1.i,  text);
	serialize_appending_newline(file, ex1.ui, text);
	serialize_appending_newline(file, ex1.c,  text);
	serialize_appending_newline(file, ex1.f,  text);
	serialize_appending_newline(file, ex1.d,  text);
	serialize_appending_newline(file, ex1.ld, text);
	serialize_appending_newline(file, ex1.cl, text);

	fclose(file);

	file = fopen("data.txt", "r");
	if (file == NULL) {
		fprintf(stderr, "Error: %s\n", strerror(errno));
		return -1;
	}
	printf("-> Reading file\n");
	memset(&ex1, 0, sizeof(ex1));
	deserialize_skipping_newline(file, ex1.i,  text);
	deserialize_skipping_newline(file, ex1.ui, text);
	deserialize_skipping_newline(file, ex1.c,  text);
	deserialize_skipping_newline(file, ex1.f,  text);
	deserialize_skipping_newline(file, ex1.d,  text);
	deserialize_skipping_newline(file, ex1.ld, text);
	//deserialize_skipping_newline(file, ex1.cl, text);
	fclose(file);

	printf("-> Result\n");
	serialize_appending_newline(stdout, ex1.i,  text);
	serialize_appending_newline(stdout, ex1.ui, text);
	serialize_appending_newline(stdout, ex1.c,  text);
	serialize_appending_newline(stdout, ex1.f,  text);
	serialize_appending_newline(stdout, ex1.d,  text);
	serialize_appending_newline(stdout, ex1.ld, text);
	serialize_appending_newline(stdout, ex1.cl, text);

	return 0;
}

int main() {
	int ret = 0;

	printf("-> Testing binary operations\n");
	ret = test_binary();
	if (ret != 0)
		return EXIT_FAILURE;
 	printf("\n");

	printf("-> Testing text operations\n");
	ret = test_text();
	if (ret != 0)
		return EXIT_FAILURE;
	printf("\n");

	return EXIT_SUCCESS;
}

