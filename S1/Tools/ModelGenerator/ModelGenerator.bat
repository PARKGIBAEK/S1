pushd %~dp0
model_generator.exe --file=../../DB/SQL/setup_database.sql --output=../../API/Model --namespace=API.Model

IF ERRORLEVEL 1 PAUSE

::PAUSE