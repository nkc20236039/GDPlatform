@echo off
setlocal

REM �r���h�f�B���N�g�����쐬�i�Ȃ���΁j
if not exist build (
    mkdir build
)

REM �r���h�f�B���N�g���Ɉړ�
cd build

REM CMake��Visual Studio�p�̃v���W�F�N�g�t�@�C������
cmake -G "Visual Studio 17 2022" ..

REM Release�\���Ńr���h
cmake --build . --config Release

REM �r���h���ꂽ���s�t�@�C�������s�i�p�X�͓K�X�ύX�j
.\Release\GDPlatform.exe

endlocal
pause