#include "include/main.hpp"
#include <conio.h>
#include <filesystem>

using namespace std;

int init_cpp() {
	clear();
	print_green("Initializing C++\n");

	print_cyan("What is the name of the project? ");
	string name;
	cin.sync();
	cin >> name;
	print_cyan("What is the name of the author? ");
	string author;
	cin.sync();
	cin >> author;
	print_cyan("What is the name of the main file? (main.cpp) ");
	string main_file;
	cin.sync();
	cin >> main_file;

	print_cyan("What is the name of the compiler? (g++) ");
	string compiler;
	cin >> compiler;

	if (compiler == "g++") {
		compiler = "g++";
	} else if (compiler == "clang++") {
		compiler = "clang++";
	} else {
		print_red("Invalid compiler\n");
		return 1;
	}

	print_cyan("What do you want to use as build system? (makefile) ");
	string build_system;
	cin.sync();
	cin >> build_system;
	if (build_system == "makefile") {
		build_system = "makefile";
	}
	else if (build_system == "cmake") {
		build_system = "cmake";
	}
	else {
		print_red("Invalid build system\n");
		return 1;
	}

	string project_path = name;
	if (filesystem::exists(project_path)) {
		print_red("Project already exists\n");
		return 1;
	}
	filesystem::create_directory(project_path);

	string src_path = project_path + "/src";
	filesystem::create_directory(src_path);

	string include_path = project_path + "/include";
	filesystem::create_directory(include_path);

	string main_path = src_path + "/" + main_file;

	FILE *fptr;
	if ((fptr = fopen(main_path.c_str(), "w")) == NULL) {
		print_red("Error opening the file\n");
		return 1;
	}
	else {
		fprintf(fptr, "%s", "#include <stdio.h>\n");
		fprintf(fptr, "%s", "#include <iostream>\n");
		fprintf(fptr, "%s", "\n");
		fprintf(fptr, "%s", "int main() {\n");
		fprintf(fptr, "%s", "\treturn 0;\n");
		fprintf(fptr, "%s", "}\n");
		fclose(fptr);
	}

	//Build system
	if (build_system == "makefile") {
		string makefile_path = project_path + "/Makefile";
		if ((fptr = fopen(makefile_path.c_str(), "w")) == NULL) {
			print_red("Error opening the file\n");
			return 1;
		}
		else {
			fprintf(fptr, "%s", "CC = " + compiler + "\n");
			fprintf(fptr, "%s", "CFLAGS = -std=c++17\n");
			fprintf(fptr, "%s", "SRC = src\n");
			fprintf(fptr, "%s", "OBJ = obj\n");
			fprintf(fptr, "%s", "INCLUDE = include\n");
			fprintf(fptr, "%s", "EXEC = " + name + "\n");
			fprintf(fptr, "%s", "all: $(EXEC)\n");
			fprintf(fptr, "%s", "$(EXEC): $(OBJ)/*.o\n");
			fprintf(fptr, "%s", "\t$(CC) $(OBJ)/*.o -o $(EXEC)\n");
			fprintf(fptr, "%s", "clean:\n");
			fprintf(fptr, "%s", "\trm -f $(OBJ)/*.o $(EXEC)\n");
			fprintf(fptr, "%s", "%.o: %.cpp\n");
			fprintf(fptr, "%s", "\t$(CC) $(CFLAGS) -c -o $@ $<\n");
			fprintf(fptr, "%s", "%.o: %.c\n");
			fprintf(fptr, "%s", "\t$(CC) $(CFLAGS) -c -o $@ $<\n");
			fprintf(fptr, "%s", "%.o: %.h\n");
			fprintf(fptr, "%s", "\t$(CC) $(CFLAGS) -c -o $@ $<\n");
			fclose(fptr);
		}
	} else if (build_system == "cmake") {
		string cmake_path = project_path + "/CMakeLists.txt";
		if ((fptr = fopen(cmake_path.c_str(), "w")) == NULL) {
			print_red("Error opening the file\n");
			return 1;
		} 
		else {
			fprintf(fptr, "%s", "cmake_minimum_required(VERSION 3.13)\n");
			fprintf(fptr, "%s", "project(" + name + ")\n");
			fprintf(fptr, "%s", "set(CMAKE_CXX_STANDARD 17)\n");
			fprintf(fptr, "%s", "set(SOURCE_FILES main.cpp)\n");
			fprintf(fptr, "%s", "add_executable(" + name + " ${SOURCE_FILES})\n");
			fclose(fptr);
		}
	

	print_green("Project created\n");
	}
}

int init_c() {
	todo();
	return 0;
}

int init_java() {
	todo();
	return 0;
}

int init_python() {
	todo();
	return 0;
}

int init_go() {
	todo();
	return 0;
}

int init_rust() {
	todo();
	return 0;
}

int init_csharp() {
	todo();
	return 0;
}

int main(int argc, char* argv[]) {

	(void)argc;
	(void)argv;

	clear();

	print_cyan("Which programming language do you want to use for the project?\n");
	print_cyan("Click the key on your keyboard\n");

	print_yellow("[1]");
	print_green(" C++\n");

	print_yellow("[2]");
	print_green(" C\n");

	print_yellow("[3]");
	print_green(" Java\n");

	print_yellow("[4]");
	print_green(" Python\n");

	print_yellow("[5]");
	print_green(" Go\n");

	print_yellow("[6]");
	print_green(" Rust\n");

	print_yellow("[7]");
	print_green(" C#\n");

	print_yellow("[q]");
	print_green(" Exit\n");

	while (true) {
		switch (getch()) {
			case '1':
				init_cpp();
				break;
			case '2':
				init_c();
				break;
			case '3':
				init_java();
				break;
			case '4':
				init_python();
				break;
			case '5':
				init_go();
				break;
			case '6':
				init_rust();
				break;
			case '7':
				init_csharp();
				break;
			case 'q':
				return 0;
		}
		break;
	}
	return(0);
}