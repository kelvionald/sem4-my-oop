set PROGRAM="%~1"

rem При запуске без параметров
%PROGRAM% > nul && goto err
echo Test 1 passed

rem При запуске с 1 параметром
%PROGRAM% "test-data/Input.txt" > nul && goto err
echo Test 2 passed

rem При поиске notSet код 0
%PROGRAM% "test-data/Input.txt" "notSet" && goto err
echo Test 3 passed

rem При поиске line выводит 2 строки результата
%PROGRAM% "test-data/Input.txt" "text" > "%TEMP%\Output.txt" || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputSearchText.txt" > nul || goto err
echo Test 4 passed

rem При поиске line выводит 1 строку результата
%PROGRAM% "test-data/Input.txt" "line" > "%TEMP%\Output.txt" || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputSearchLine.txt" > nul || goto err
echo Test 5 passed

rem При поиске Some выводит 1 строку результата
%PROGRAM% "test-data/Input.txt" "Some" > "%TEMP%\Output.txt" || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputSearchSome.txt" > nul || goto err
echo Test 6 passed

rem При запуске на не существующем файле
%PROGRAM% "test-data/MissingFile.txt" "Some" > "%TEMP%\Output.txt" && goto err
echo Test 7 passed

echo OK
exit 0

:err
echo Program testing failed
exit 1