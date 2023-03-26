n1=$1
n2=$2
n3=$3
if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then
echo "Number 1 is the largest: $n1"
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ] 
then
echo "Number 2 is the largest: $n2"
elif [ $n3 -gt $n1 ] && [ $n3 -gt $n2 ] 
then
echo "Number 3 is the largest: $n3"
fi
