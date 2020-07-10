@echo off

echo ÕýÔÚÉ¾³ýBuild
:rm_build
if exist Build rd Build /q /s
timeout 1
if exist Build goto rm_build

mkdir Build
cd Build
cmake -DCMAKE_INSTALL_PREFIX=../Install -DGLOG_ROOT=G:\ThirdParty\glog\v0.4.0\Visual_Studio_15_2017\Win64\MT\Debug -DCMAKE_UTILITY_ROOT=E:\GitRepo\CMakeUtility -G "Visual Studio 15 2017 Win64" ..
cmake --build . --config Debug

pause