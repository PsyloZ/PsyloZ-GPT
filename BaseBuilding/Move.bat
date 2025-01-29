@echo off

setlocal enabledelayedexpansion
set "Prefix=Wall"
set "Directory=%CD%\%Prefix%"

set "materials[0]=Frame"
set "materials[1]=Wood"
set "materials[2]=Metal"
set "materials[3]=Concrete"

set "arrayLength=3"

echo Debug: Prefix=%Prefix%
echo Debug: Directory=%Directory%

for /l %%i in (0, 1, %arrayLength%) do (
    set "material=!materials[%%i]!"
    MoveObject -P %Prefix% RearmedServer\BaseBuilding\!material!\%Prefix% RearmedServer\BaseBuilding\%Prefix%
    MoveObject -P %Prefix% RearmedServer\BaseBuilding\Camonets RearmedServer\BaseBuilding\%Prefix%
    MoveObject -P %Prefix% RearmedServer\BaseBuilding\!material! RearmedServer\BaseBuilding\Materials\!material!


REM    set "search_string=RearmedServer\BaseBuilding\!material!\%Prefix%"
REM    set "replace_string=RearmedServer\BaseBuilding\%Prefix%"
REM
REM    REM Iterate through all .cpp files recursively in the directory
REM    for /R "%Directory%" %%j in (*.cpp) do (
REM        set "inputFile=%%j"
REM        set "outputFile=!inputFile!.tmp"
REM
REM        REM Find and replace string in each line of the input file
REM        (
REM            for /f "usebackq delims=" %%k in ("!inputFile!") do (
REM                set "line=%%k"
REM                setlocal DisableDelayedExpansion
REM                set "line=!line:%search_string%=%replace_string%!"
REM                echo(!line!
REM                endlocal
REM            )
REM        ) > "!outputFile!"
REM
REM        REM Replace the original input file with the updated content
REM        move /y "!outputFile!" "!inputFile!" > nul
REM    )
)

endlocal
exit /b
