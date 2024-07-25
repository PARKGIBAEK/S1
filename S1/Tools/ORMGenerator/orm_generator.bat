pushd %~dp0
orm_generator.exe --host=localhost --user=root --password=tkdring --database=test --port=3308 --output=../../GameServer/DB/ORM

IF ERRORLEVEL 1 PAUSE

::PAUSE