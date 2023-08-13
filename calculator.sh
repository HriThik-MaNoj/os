echo "Enter two numbers : "
read a
read b
echo "Enter the choice : "
echo "1.Addtion"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"
read ch

case $ch in 
    1) res=$((a+b))
        ;;
    2) res=$((a-b))
        ;;
    3) res=$((a*b))
        ;;
    4) res=$((a/b))
        ;;
esac
echo "Result : $res"
