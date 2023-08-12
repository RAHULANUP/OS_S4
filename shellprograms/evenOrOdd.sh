echo "Enter the number"
read n
r=` expr $n % 2 ` 
if [ $r -eq 0 ]
then 
echo "Even number"
else
echo "Odd number"
fi
