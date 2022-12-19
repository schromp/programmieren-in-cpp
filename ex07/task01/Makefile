all: overhead.cpp
	g++ -o allcalls overhead.cpp stopwatch.hpp stopwatch.cpp -DVERBOSE
task02: overhead.cpp
	g++ -o overhead overhead.cpp stopwatch.hpp stopwatch.cpp -DTASK02
task03: overhead.cpp
	g++ -o casting overhead.cpp stopwatch.hpp stopwatch.cpp -DTASK03
clean:
	rm casting overhead allcalls
