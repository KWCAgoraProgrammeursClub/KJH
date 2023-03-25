#!/bin/sh

cat /dev/random | head -c 931 > /tmp/pt
./encrypt mypass /tmp/pt /tmp/ct
echo -n '1' >> /tmp/ct
if ./decrypt mypass /tmp/ct /tmp/co; then
  echo "Decrypt succeeds, which is not good"
  exit 1
else
  echo "Decrypt fails, which is good"
fi

echo "Ok"
