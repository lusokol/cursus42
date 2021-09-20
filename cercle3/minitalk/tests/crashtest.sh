#!/bin/sh

for i in `seq 1 50`; do
	../client $1 "$(cat text_1k.txt)"
	echo "tour $i"
done