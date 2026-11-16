@echo off
cd /d "%~dp0"
echo Compilando Sistema de Gerenciamento de Biblioteca...
g++ -std=c++11 -Wall -Wextra -pedantic -o biblioteca.exe src\main.cpp
if %errorlevel% neq 0 (
  echo.
  echo Falha na compilacao.
  pause
  exit /b %errorlevel%
)
echo.
echo Compilacao concluida com sucesso.
echo Para executar: biblioteca.exe
pause
