#!/bin/bash

echo "enter the number : "
read a
sum=0
temp=$a
b=0
c=10
while [ $a -gt $b ]
do
    rem=$((a % 10))
    sum=$((sum + rem*rem*rem))
    a=$((a / 10))
done
if [ $sum -eq $temp ]
then
    echo "armstrong"
else
    echo "not armstrong"
fi

