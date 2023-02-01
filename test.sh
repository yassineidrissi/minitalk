#!/bin/bash

SERVERID=$(top -l 1 | grep server | awk '{print $1}' | head  -1)
PROCCESS=$(top -l 1 | grep client | wc -l | tr -d ' ')
for i in {1..100000}
do
		./client $SERVERID  "😀😀😀😀😀😀😀😀😀😀😀😀😀😀😀😀😀😀😀😀😀😀"
done
