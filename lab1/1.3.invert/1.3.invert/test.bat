set PROGRAM="%~1"

rem Без параметров
%PROGRAM% > nul && goto err
echo Test 1 passed

rem Некорректный ввод формата 1
%PROGRAM% "test-data/IncorrectFormat1.txt" > nul && goto err
echo Test 2 passed

rem Некорректный ввод формата 2
%PROGRAM% "test-data/IncorrectFormat2.txt" > nul && goto err
echo Test 3 passed

rem Пустой файл
%PROGRAM% "test-data/Empty.txt" > nul && goto err
echo Test 4 passed

rem Ввод не числового значения
%PROGRAM% "test-data/IncorrectValue.txt" > nul && goto err
echo Test 5 passed

rem Ввод корректной квадратной матрицы
%PROGRAM% "test-data/Matrix.txt" > "%TEMP%\Output.txt" || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputMatrix.txt" > nul || goto err
echo Test 6 passed

rem Ввод вырожденной матрицы
%PROGRAM% "test-data/SingularMatrix.txt" > nul  && goto err
echo Test 7 passed

echo OK
exit 0

:err
echo Program testing failed
exit 1