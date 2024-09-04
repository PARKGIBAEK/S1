pushd %~dp0
pyinstaller --onefile PacketGenerator.py

IF EXIST .\dist\PacketGenerator.exe (
    MOVE .\dist\PacketGenerator.exe .\PacketGenerator.exe
) ELSE (
    echo ERROR: PacketGenerator.exe not found in .\dist
    exit /b 1
)

@RD /S /Q .\build
@RD /S /Q .\dist
DEL /S /F /Q .\PacketGenerator.spec
PAUSE