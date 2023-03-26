sum=$(( $1 + $2 + $3 + $4 + $5 ))
avg=$(($sum/5))
if [ $avg -ge 90 -a $avg -le 100 ]
then
echo "A"
elif [ $avg -ge 70 -a $avg -le 89 ]
then
echo "B"
elif [ $avg -ge 40 -a $avg -le 69 ]
then
echo "C"
else
echo "F"
fi