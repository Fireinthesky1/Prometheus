@ECHO OFF
REM Build script for Prometheus
SetLocal EnableDelayedExpansion

REM Get a list of all the .c files
Set cFilenames =
FOR /R %%f in (*.c) do (
    SET cFilenames=!cFilenames! %%f
)

REM echo "Files:" %cFilenames%

SET assembly=prometheus
SET compilerFlags=-g
REM -Wall -Werror
SET includeFlags=-Isrc
SET linkerFlags=-L../bin/
SET defines=

ECHO "Building %assembly%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%