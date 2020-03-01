set PROGRAM="%~1"

rem Без параметров
%PROGRAM% > nul && goto err
echo Test 1 passed

rem Несуществующий файл
%PROGRAM% crypt "test-data/NoExist.txt" "%TEMP%\Output.txt" 1 > nul && goto err
echo Test 2 passed

rem Отрицательный ключ
%PROGRAM% crypt "test-data/NoExist.txt" "%TEMP%\Output.txt" -1 > nul && goto err
echo Test 3 passed

rem Слишком длинный ключ
%PROGRAM% crypt "test-data/NoExist.txt" "%TEMP%\Output.txt" 256 > nul && goto err
echo Test 4 passed

rem Пустой файл
%PROGRAM% crypt "test-data/Empty.txt" "%TEMP%\Output.txt" 1 || goto err
rem fc.exe "%TEMP%\Output.txt" "test-data/Empty.txt" > nul || goto err
echo Test 5 passed

rem Шифрование символа с ключем 10
%PROGRAM% crypt "test-data/Input3.txt" "%TEMP%\Output.txt" 10 || goto err
fc.exe "%TEMP%\Output.txt" "test-data/Output3-10.txt" > nul || goto err
echo Test 6 passed

rem Шифрование символа с ключем 11
%PROGRAM% crypt "test-data/Input3.txt" "%TEMP%\Output.txt" 11 || goto err
fc.exe "%TEMP%\Output.txt" "test-data/Output3-11.txt" > nul || goto err
echo Test 7 passed

rem Дешифрование символа с ключем 10
%PROGRAM% decrypt "test-data/Output3-10.txt" "%TEMP%\Output.txt" 10 || goto err
fc.exe "%TEMP%\Output.txt" "test-data/Input3.txt" > nul || goto err
echo Test 8 passed

rem Шифрование текста с ключем 33
%PROGRAM% crypt "test-data/InputText.txt" "%TEMP%\Output.txt" 33 || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputText.txt" > nul || goto err
echo Test 9 passed

rem Дешифрование текста с ключем 33
%PROGRAM% decrypt "test-data/OutputText.txt" "%TEMP%\Output.txt" 33 || goto err
fc.exe "%TEMP%\Output.txt" "test-data/InputText.txt" > nul || goto err
echo Test 10 passed

rem Некорректный режим
%PROGRAM% noncrypt "" "" 1 > nul && goto err
echo Test 11 passed

rem Пустое имя входного файла
%PROGRAM% crypt "" "" 1 > nul && goto err
echo Test 12 passed

rem Пустое имя выходного файла
%PROGRAM% crypt "1" "" 1 > nul && goto err
echo Test 13 passed

echo OK
exit 0

:err
echo Program testing failed
exit 1