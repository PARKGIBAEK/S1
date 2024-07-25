pushd %~dp0
pyinstaller --onefile model_generator.py
MOVE .\dist\model_generator.exe .\model_generator.exe
@RD /S /Q .\build
@RD /S /Q .\dist
DEL /S /F /Q .\model_generator.spec
PAUSE