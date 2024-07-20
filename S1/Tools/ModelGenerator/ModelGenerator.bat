pushd %~dp0
pyinstaller --onefile ModelGenerator.py
MOVE .\dist\ModelGenerator.exe .\ModelGenerator.exe
@RD /S /Q .\build
@RD /S /Q .\dist
DEL /S /F /Q .\ModelGenerator.spec
PAUSE