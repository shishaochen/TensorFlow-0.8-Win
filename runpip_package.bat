@echo off
cd %~dp0

set CONFIG=release
if not exist %CONFIG% (
  echo "You should build with CMake first in "%CONFIG%" dir first"
  exit /B 1
)

echo "Cleaning..."
set WHEEL=%CONFIG%\wheel
if exist %WHEEL% (
  rmdir /S /Q %WHEEL%
)
mkdir %WHEEL%

echo "Copying..."
mkdir %WHEEL%\external
xcopy external %WHEEL%\external\ /S /Q
mkdir %WHEEL%\tensorflow
xcopy tensorflow %WHEEL%\tensorflow\ /S /Q
copy %CONFIG%\_pywrap_tensorflow.dll %WHEEL%\tensorflow\python\_pywrap_tensorflow.pyd
copy tensorflow\tools\pip_package\setup.py %WHEEL%
copy tensorflow\tools\pip_package\README %WHEEL%
copy tensorflow\tools\pip_package\MANIFEST.in %WHEEL%

echo "Packaging..."
cd %WHEEL%
python setup.py bdist_wheel
cd dist
move tensorflow-0.8.1-py3-none-any.whl tensorflow-0.8.1-py3-none-win_amd64.whl

echo "Finished!"