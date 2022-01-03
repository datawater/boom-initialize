#include "include/main.hpp"
#include <conio.h>
#include <string.h>
#include <filesystem>

using namespace std;

int init_cpp() {
	clear();
	print_green("Initializing C++\n");
	print_cyan("What is the name of the project? ");
	string name;
	cin.sync();
	cin >> name;
	if (name.length() == 0) {
		error("Invalid name");
	}
	print_cyan("What is the name of the author? ");
	string author;
	cin.sync();
	cin >> author;
	if (author.length() == 0) {
		error("Invalid author name\n");
	}
	print_cyan("What is the name of the main file? (main.cpp) ");
	string main_file;
	cin.sync();
	cin >> main_file;
	if (main_file.length() < 4) {
		main_file = "main.cpp";
		warn("Invalid main file name, using default\n");
	}
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

	//ask if you want to use git
	print_cyan("Do you want to use git? (y/n) ");
	string git;
	cin.sync();
	cin >> git;
	if (git == "y") {
		git = "y";
	} else if (git == "n") {
		git = "n";
	} else {
		print_red("Invalid answer\n");
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
	info("Creating project directory");
	filesystem::create_directory(project_path);

	string src_path = project_path + "/src";
	filesystem::create_directory(src_path);

	string include_path = project_path + "/include";
	filesystem::create_directory(include_path);

	string main_path = src_path + "/" + main_file;


	info("Creating main file");
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
	info("Creating build system");
	if (build_system == "makefile") {
		string makefile_path = project_path + "/Makefile";
		if ((fptr = fopen(makefile_path.c_str(), "w")) == NULL) {
			print_red("Error opening the file\n");
			return 1;
		}
		else {
			fprintf(fptr, "%s", ("CC = " + compiler + "\n").c_str());
			fprintf(fptr, "%s", "CFLAGS = -Wall -Wextra -static\n");
			fprintf(fptr, "%s", "SRC = src/*.cpp\n");
			fprintf(fptr, "%s", "OUTPUT = out/main\n");
			fprintf(fptr, "%s", "\n");
			fprintf(fptr, "%s", "main:\n");
			fprintf(fptr, "%s", "	$(CC) $(CFLAGS) $(SRC) -o $(OUTPUT)\n");
			fprintf(fptr, "%s", "	chmod +x $(OUTPUT)\n");
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
			fprintf(fptr, "%s", ("project(" + name + ")\n").c_str());
			fprintf(fptr, "%s", "set(CMAKE_CXX_STANDARD 17)\n");
			fprintf(fptr, "%s", ("set(SOURCE_FILES" + main_file + ")\n").c_str());
			fprintf(fptr, "%s", ("add_executable(" + name + " ${SOURCE_FILES})\n").c_str());
			fclose(fptr);
		}
	}
	info("Creating the git repository");
	if (git == "y") {
		print_cyan("Whats the git repo? (link)");
		string git_repo;
		cin.sync();
		cin >> git_repo;
		if (git_repo.length() == 0) {
			error("Invalid git repo");
		}

		stringstream command;
		command << "git init " << project_path << " && git remote add origin " << git_repo << " && git pull origin master";

		system(command.str().c_str());

	}
	success("Project created");
	return (0);
}

int init_c() {
	clear();
	print_green("Initializing C++\n");

	print_cyan("What is the name of the project? ");
	string name;
	cin.sync();
	cin >> name;
	if (name.length() == 0) {
		error("Invalid name");
	}
	print_cyan("What is the name of the author? ");
	string author;
	cin.sync();
	cin >> author;
	if (author.length() == 0) {
		error("Invalid author name\n");
	}
	print_cyan("What is the name of the main file? (main.c) ");
	string main_file;
	cin.sync();
	cin >> main_file;
	if (main_file.length() < 4) {
		main_file = "main.cpp";
		warn("Invalid main file name, using default\n");
	}

	print_cyan("What is the name of the compiler? (gcc) ");
	string compiler;
	cin >> compiler;

	if (compiler == "gcc") {
		compiler = "gcc";
	} else if (compiler == "clang") {
		compiler = "clang";
	} else {
		error("Invalid compiler\n");
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
			fprintf(fptr, "%s", ("CC = " + compiler + "\n").c_str());
			fprintf(fptr, "%s", "CFLAGS = -Wall -Wextra -static\n");
			fprintf(fptr, "%s", "SRC = src/*.c\n");
			fprintf(fptr, "%s", "OUTPUT = out/main\n");
			fprintf(fptr, "%s", "\n");
			fprintf(fptr, "%s", "main:\n");
			fprintf(fptr, "%s", "	$(CC) $(CFLAGS) $(SRC) -o $(OUTPUT)\n");
			fprintf(fptr, "%s", "	chmod +x $(OUTPUT)\n");
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
			fprintf(fptr, "%s", ("project(" + name + ")\n").c_str());
			fprintf(fptr, "%s", ("CC = " + compiler + "\n").c_str());
			fprintf(fptr, "%s", ("set(SOURCE_FILES src/" + main_file + ")\n").c_str());
			fprintf(fptr, "%s", ("add_executable(" + name + " ${SOURCE_FILES})\n").c_str());
			fclose(fptr);
		}
	

	print_green("Project created\n");
	}
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