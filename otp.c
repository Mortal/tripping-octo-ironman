#include <stdio.h>
#include "sha512.c"
int main(int argc, char ** argv) {
	unsigned char digest[SHA512_DIGEST_LENGTH];
	unsigned char digest2[SHA512_DIGEST_LENGTH];
	unsigned char input[] = { 100, 117, 110, 110, 95, 100, 117, 110, 110, 95, 100, 117, 110, 110};
	size_t inputlen = 14;
	SHA512(input, inputlen, digest);
	memcpy(digest2, digest, SHA512_DIGEST_LENGTH);
	int c;
	const unsigned char * p = digest;
	const unsigned char * end = digest + SHA512_DIGEST_LENGTH;
	for (c = getchar(); c != EOF; c = getchar()) {
		if (p == end) {
			SHA512(digest2, SHA512_DIGEST_LENGTH, digest);
			memcpy(digest2, digest, SHA512_DIGEST_LENGTH);
			p = digest;
		}
		putchar(c ^ *p++);
	}
	return 0;
}
