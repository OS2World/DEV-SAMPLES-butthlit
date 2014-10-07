# IBM Developer's Workframe/2 Make File Creation run at 20:11:18 on 04/06/94

# Make File Creation run in directory:
#   C:\SOURCES\C\test;

.SUFFIXES:

.SUFFIXES: .c .cpp .cxx .rc

ALL: test.EXE \
     test.RES

test.EXE:  \
  test.RES \
  testWP.OBJ \
  TESTMAIN.OBJ \
  test.MAK
   ICC.EXE @<<
 /B" /de /pmtype:pm /nop /nologo"
 /Fe"test.EXE"
testWP.OBJ
TESTMAIN.OBJ
<<
   RC test.RES test.EXE

{.}.rc.res:
   RC -r .\$*.RC

{.}.c.obj:
   ICC.EXE /Sp1 /Q /Ti /Gm /C   .\$*.c

{.}.cpp.obj:
   ICC.EXE /Sp1 /Q /Ti /Gm /C   .\$*.cpp

{.}.cxx.obj:
   ICC.EXE /Sp1 /Q /Ti /Gm /C   .\$*.cxx

!include test.DEP
