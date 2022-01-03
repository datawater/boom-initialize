CXX=g++
CXXFLAGS=-Wall -Wextra -Wswitch-enum -Werror -Wpedantic -std=c++17 -pedantic -fno-exceptions -ggdb -static
FILES=src/main.cpp
OUTPUT=out/main

main:
	@echo "Compiling..."
	@echo "[CMD] ${CXX} ${CXXFLAGS} ${FILES} -o ${OUTPUT}"
	@$(CXX) $(CXXFLAGS) $(FILES) -o $(OUTPUT)
	@echo "[CMD] chmod +x ./${OUTPUT}"
	@chmod +x ./$(OUTPUT)

run:
	@echo "Compiling and running..."

	@echo "[CMD] ${CXX} ${CXXFLAGS} ${FILES} -o ${OUTPUT}"
	@$(CXX) $(CXXFLAGS) $(FILES) -o $(OUTPUT)
	@echo "[CMD] chmod +x ./${OUTPUT}"
	@chmod +x ./$(OUTPUT)
	@echo "[CMD] ./${OUTPUT}"
	@./$(OUTPUT)

just_run:
	@echo "Running..."
	@echo "[CMD] ./${OUTPUT}"
	@./$(OUTPUT)

