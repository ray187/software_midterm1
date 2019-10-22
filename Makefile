all: lab9 test_lab09

lab9: lab9.cpp
	g++ lab9.cpp -Wall -olab9

test_lab09: test_lab09.cpp
	g++ test_lab09.cpp -Wall -otest_lab09

clean:
	rm -f lab9
	rm -f test_lab09
