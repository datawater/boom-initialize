CXX=g++
CXXFLAGS=-Wall -Werror -Wextra -std=c++17 -pedantic -fno-exceptions -ggdb -static
FILES=main.cpp
OUTPUT=out/main

main:
	$(CXX) $(CXXFLAGS) $(FILES) -o $(OUTPUT)
	chmod +x ./out/main

run:
	$(CXX) $(CXXFLAGS) $(FILES) -o $(OUTPUT)
	chmod +x ./out/main
	./out/main

just_run:
	./out/main

