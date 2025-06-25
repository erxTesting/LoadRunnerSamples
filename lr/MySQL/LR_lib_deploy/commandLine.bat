mkdir c:\MySQL
7za x archive.zip -oc:\MySQL -y
c:
cd %LG_PATH%
xcopy c:\MySQL /e /y
pause
