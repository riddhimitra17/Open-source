#!/bin/bash
read -p "Enter first number: " num1
read -p "Enter second number: " num2

temp=$num1
num1=$num2
num2=$temp

echo "After swapping the numbers are:"
echo "first=$num1 second=$num2"