for file in $(find . -type f -name "*.c")
do
trimmedName=`echo $file | cut -d'/' -f2`
prog_name=$(echo $trimmedName | cut -d'.' -f1)
gcc -o $prog_name $trimmedName 2>/dev/null 
if [ -f $prog_name ] 
then
    ans=$(./$prog_name) 
    if [ $ans -eq 20 ]
    then   
        score=10
    else
        score=7
    fi
else
    score=5 
fi
printf "%s\t\t%d\n" $trimmedName $score
done

