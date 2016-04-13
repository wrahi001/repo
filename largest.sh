#!/bin/sh
first=$1
second=$2
third=$3

if [ $# -ne 3 ]; then
	echo "wrong number of parameters"
	exit
fi

if [ $first -ge $second ]; then
	largest=$first
else
	largest=$second
fi

if [ $largest -ge $third ]; then
	echo $largest
else
	echo $third
fi


