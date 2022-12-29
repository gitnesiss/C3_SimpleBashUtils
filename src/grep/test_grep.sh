#!/bin/bash

COUNTER=0
COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
LOG_FILE=log_error.txt

echo "Create log_file: $LOG_FILE"
echo ""
echo "" > $LOG_FILE

TEST01="goo ../testFile/grep_test1.txt"
TEST02="-e goo -e yan ../testFile/grep_test1.txt"
TEST03="-in goo ../testFile/grep_test1.txt"
TEST04="-inv -e goo -e ya -e ir -e te -e e ../testFile/grep_test1.txt"
TEST05="-inc goo ../testFile/grep_test1.txt"
TEST06="-inl goo ../testFile/grep_test1.txt"
TEST07="-n -h goo ../testFile/grep_test1.txt ../testFile/grep_test2.txt"
TEST08="-s goo ../testFile/grep_test.txt"
TEST09="-f ../testFile/patterns_for_test.txt ../testFile/grep_test1.txt"
TEST10="-on -f ../testFile/patterns_for_test.txt ../testFile/grep_test1.txt"
TEST11="-oni -e ceo -f ../testFile/patterns_for_test.txt ../testFile/grep_test1.txt"

testArray=( "$TEST01" "$TEST02" "$TEST03" "$TEST04" "$TEST05" "$TEST06" 
            "$TEST07" "$TEST08" "$TEST09" "$TEST10" "$TEST11")

for i in "${testArray[@]}"; do
    (( COUNTER++ ))
    TEST=$i
    echo "   TEST $COUNTER"
    echo
    echo "./s21_grep $TEST"
    ./s21_grep $TEST > test_result_s21_grep.txt
    echo "grep $TEST"
    grep $TEST > test_result_grep.txt
    DIFF_RES="$(diff -s test_result_s21_grep.txt test_result_grep.txt)"
    if [ "$DIFF_RES" == "Files test_result_s21_grep.txt and test_result_grep.txt are identical" ]
    then
        echo "TEST $COUNTER SUCCESS"
        (( COUNTER_SUCCESS++ ))
    else
        echo "TEST $COUNTER FAIL"
        echo "$TEST" >> log.txt
        (( COUNTER_FAIL++ ))
    fi
    echo 
    echo
done

for var in -i -v -c -l -n -o
do
    for var2 in -i -v -c -l -n -o
    do
        for var3 in -i -v -c -l -n -o
        do
            if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ]
            then
                (( COUNTER++ ))
                TEST3="$var $var2 $var3 goo ../testFile/grep_test1.txt"
                echo "   TEST $COUNTER"
                echo
                echo "./s21_grep $TEST3"
                ./s21_grep $TEST3 > test_result_s21_grep.txt
                echo "grep $TEST3"
                grep $TEST3 > test_result_grep.txt
                DIFF_RES="$(diff -s test_result_s21_grep.txt test_result_grep.txt)"
                if [ "$DIFF_RES" == "Files test_result_s21_grep.txt and test_result_grep.txt are identical" ]
                then
                    echo "TEST $COUNTER SUCCESS"
                    (( COUNTER_SUCCESS++ ))
                else
                    echo "TEST $COUNTER FAIL"
                    echo "$TEST" >> log.txt
                    (( COUNTER_FAIL++ ))
                fi
                echo 
                echo
            fi
        done
    done
done
rm test_result_s21_grep.txt test_result_grep.txt

if [ $COUNTER_FAIL == 0 ] 
then
    rm $LOG_FILE
    echo "File $LOG_FILE deleted."
    echo ""
fi

echo "Количество тестов: $COUNTER"
echo "Тест пройден (SUCCESS): $COUNTER_SUCCESS"
echo "Тест провален   (FAIL): $COUNTER_FAIL"