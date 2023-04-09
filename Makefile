#Variables
CC = g++
CFLAGS = -g -Wall -std=c++17

# Linking all the files and run the tests. Use your own header and
# object files.

main: check.cc checkbook.cc date.cc commented_main.cc
	$(CC) check.cc checkbook.cc date.cc commented_main.cc  -o commented_main.exe

run_main: commented_main.out
	./commented_main.exe

commented_main_debug.out: check.cc checkbook.cc date.cc commented_main.cc
	$(CC) -g check.cc checkbook.cc date.cc commented_main.cc -o commented_main_debug.out

testcheck.out: check.cc testcheck.cc date.cc
	$(CC) $(CFLAGS) check.cc testcheck.cc date.cc -o testcheck.out

testcheckbook.out: check.cc checkbook.cc date.cc
	$(CC) check.cc checkbook.cc date.cc -o testcheckbook.out

testdate.out: date.cc testdate.cc
	$(CC) $(CFLAGS) date.cc testdate.cc -o testcheck.out

test_file_read.out: test_file_read.cc
	$(CC) $(CFLAGS) test_file_read.cc -o test_file_read.out

date.o: date.cc date.h
	$(CC) -c $(CFLAGS) date.cc -o date.o

check.o: check.cc check.h date.o
	$(CC) -c $(CFLAGS) check.cc -o check.o

checkbook.o: checkbook.cc checkbook.h
	$(CC) -c $(CFLAGS) checkbook.cc -o checkbook.o

testcheck.o: testcheck.cc check.h
	$(CC) -c $(CFLAGS) testcheck.cc -o testcheck.o

test_check.out: check.cc testcheck.cc date.cc
	$(CC) $(CFLAGS) check.cc testcheck.cc date.cc -o test_check.out

test_file_read.out: test_file_read.cc
	$(CC) $(CFLAGS) test_file_read.cc -o test_file_read.out
clean:
	rm -rf *.o *.out