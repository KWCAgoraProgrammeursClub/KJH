OBJECTS=sha2.o aes.o absorb_file.o derive_key.o hmac.o random_iv.o encapsulate.o decapsulate.o
ENCRYPT=encrypt
DECRYPT=decrypt
CFLAGS=-g -Wall -Wextra -DTRUE_RANDOM=1

all: $(ENCRYPT) $(DECRYPT)

$(ENCRYPT): $(OBJECTS) encrypt.o
	$(CC) -o $(ENCRYPT) $(OBJECTS) encrypt.o

$(DECRYPT): $(OBJECTS) decrypt.o
	$(CC) -o $(DECRYPT) $(OBJECTS) decrypt.o

clean:
	rm -f $(OBJECTS) $(ENCRYPT) $(DECRYPT) encrypt.o decrypt.o

archive: clean
	RELEASE=$$(cat release); \
	/bin/echo "  [TAR] ~/filecrypto-src-$$RELEASE.tar.gz"; \
	cd .. && \
	  tar czf ~/filecrypto-src-$$RELEASE.tar.gz \
	  --transform "s,^,filecrypto-$$RELEASE/," \
	  --exclude=\.git \
	  .

test:
	./test_001.sh
	./test_002.sh
	./test_003.sh
