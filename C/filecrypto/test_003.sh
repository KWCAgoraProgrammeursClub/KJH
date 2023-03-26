#!/bin/sh

set -e

echo "Small message." > /tmp/pt
./encrypt mypass /tmp/pt /tmp/ct
./decrypt mypass /tmp/ct /tmp/co
diff /tmp/pt /tmp/co

echo "Ok"
