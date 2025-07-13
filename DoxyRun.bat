@echo off

chcp 65001
set LANG=ja_JP.UTF-8

doxygen Doxyfile

start "" "chrome.exe" "%~dp0./docs/html/index.html"