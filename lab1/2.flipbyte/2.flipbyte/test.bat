set PROGRAM="%~1"

rem Без параметров
%PROGRAM% > nul && goto err
echo Test 1 passed

rem Число больше чем 1 байт
%PROGRAM% 1234 > nul && goto err
echo Test 2 passed

rem Не число
%PROGRAM% abcd > nul && goto err
echo Test 3 passed

rem Граничное число 1 байта
%PROGRAM% 256 > nul && goto err
echo Test 4 passed

rem Число 6 из примера
%PROGRAM% 6 > "%TEMP%\Output.txt" || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputForSix.txt" > nul || goto err
echo Test 5 passed

rem Число 0
%PROGRAM% 0 > "%TEMP%\Output.txt" || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputForZero.txt" > nul || goto err
echo Test 6 passed

echo OK
exit 0

:err
echo Program testing failed
exit 1