echo -----------------------
echo 'Menu Implementation'
echo -----------------------
echo 1. Display the current working directory.
echo 2. Check whether an input number is even or odd.
echo 3. Display the number of counts of all the files in the directory.
echo 4. Print the long listing of all the files.
echo Enter your choice
read choice
case $choice in
    1)pwd;;
    2)echo "Enter number"
      read n
      rem=$(( $n % 2 ))
      if [ $rem -eq 0 ]
      then
      echo "Number is even"
      else
      echo "Number is odd"
      fi;;
    3)ls | wc -l;;
    4)ls -1;;
    *)echo This is not a choice
esac