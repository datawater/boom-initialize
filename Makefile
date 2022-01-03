CXX=g++
CXXFLAGS=-Wall -Wextra -Wswitch-enum -Werror -Wpedantic -std=c++17 -pedantic -fno-exceptions -ggdb -static
CXXASSEMBLY=$(CXXFLAGS) -S
FILES=src/main.cpp
OUTPUT=out/main

main:
	@echo "[INFO] Compiling..."
	@echo "[CMD] ${CXX} ${CXXFLAGS} ${FILES} -o ${OUTPUT}"
	@$(CXX) $(CXXFLAGS) $(FILES) -o $(OUTPUT)
	@echo "[CMD] chmod +x ./${OUTPUT}"
	@chmod +x ./$(OUTPUT)

run:
	@echo "[INFO] Compiling and running..."

	@echo "[CMD] ${CXX} ${CXXFLAGS} ${FILES} -o ${OUTPUT}"
	@$(CXX) $(CXXFLAGS) $(FILES) -o $(OUTPUT)
	@echo "[CMD] chmod +x ./${OUTPUT}"
	@chmod +x ./$(OUTPUT)
	@echo "[CMD] ./${OUTPUT}"
	@./$(OUTPUT)

just_run:
	@echo "[INFO] Running..."
	@echo "[CMD] ./${OUTPUT}"
	@./$(OUTPUT)

assembly:
	@echo "[INFO] Converting to assembly..."
	@echo "[CMD] ${CXX} ${CXXASSEMBLY} ${FILES} -o ${OUTPUT}.s"
	@$(CXX) $(CXXASSEMBLY) $(FILES) -o $(OUTPUT).s

windows:
	@echo "[INFO] Compiling for Windows..."
	@echo "[CMD] ${CXX} ${CXXFLAGS} ${FILES} -o ${OUTPUT}.exe"
	@$(CXX) $(CXXFLAGS) $(FILES) -o $(OUTPUT).exe

windows_run:
	@echo "[INFO] Compiling and running for Windows..."
	@echo "[CMD] ${CXX} ${CXXFLAGS} ${FILES} -o ${OUTPUT}.exe"
	@$(CXX) $(CXXFLAGS) $(FILES) -o $(OUTPUT).exe
	@echo "[CMD] chmod +x ./${OUTPUT}.exe"
	@echo "[CMD] ${OUTPUT}.exe"
	@$(OUTPUT).exe

windows_just_run:
	@echo "[INFO] Running for Windows..."
	@echo "[CMD] ${OUTPUT}.exe"
	@$(OUTPUT).exe