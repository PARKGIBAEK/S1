pushd %~dp0
pyinstaller --onefile orm_generator.py
MOVE .\dist\orm_generator.exe .\orm_generator.exe
@RD /S /Q .\build
@RD /S /Q .\dist
DEL /S /F /Q .\orm_generator.spec
PAUSE