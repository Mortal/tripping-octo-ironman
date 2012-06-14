CC=clang
CFLAGS=-fno-omit-frame-pointer -faddress-sanitizer -Wall -Wextra -g
otp: otp.o cryptlib.o
	$(CC) $(CFLAGS) $(LDFLAGS) -lssl -lcrypto -o $@ $^

clean:
	$(RM) otp otp.o cryptlib.o
