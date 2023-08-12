echo "Enter a number : "
read n

fact=1
for((i=1;i<=n;i++))
do
fact=$( expr $fact \* $i )
done
echo "THE FACTORIAL OF THE NUMBER IS $fact"