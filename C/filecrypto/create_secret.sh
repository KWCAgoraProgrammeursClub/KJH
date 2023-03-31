#!/bin/sh

echo "unsigned char secret[] = {" > secret.h
cat /dev/random | head -c 32 | hexdump -v -e '16/1 "0x%.2x," "\n"' | \
	head -c -2 >> secret.h
echo >> secret.h
echo "};" >> secret.h
