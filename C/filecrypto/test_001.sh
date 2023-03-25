#!/bin/sh

set -e

cat /dev/random | head -c 931 > /tmp/pt
./encrypt mypass /tmp/pt /tmp/ct
./decrypt mypass /tmp/ct /tmp/co
diff /tmp/pt /tmp/co

echo "Ok"
