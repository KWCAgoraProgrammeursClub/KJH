#!/bin/sh

echo "Small message." > /tmp/pt
./encrypt mypass /tmp/pt /tmp/ct

head -c -1 < /tmp/ct > /tmp/ct2
echo -n '1' >> /tmp/ct2

if ./decrypt mypass /tmp/ct2 /tmp/co; then
  echo "Decrypt succeeds, which is not good"
  exit 1
else
  echo "Decrypt fails, which is good"
fi

echo "Ok"
