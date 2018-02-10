@echo off
setlocal enableextensions
	IF NOT EXIST msvc2015/ (
		md msvc2015
	) ELSE (
		echo msvc2015 exists, skipping
	)
endlocal

cd msvc2015 && ^
cmake -G "Visual Studio 15 2017" ..\.. && ^
cd ..
