#include <stdio.h>
#include <iostream>
#include <sstream>

void print_red(const char *text) {
    printf("\033[0;31m");
    printf("%s", text);
    printf("\033[0m");
}

void print_green(const char *text) {
    printf("\033[0;32m");
    printf("%s", text);
    printf("\033[0m");
}

void print_yellow(const char *text) {
    printf("\033[0;33m");
    printf("%s", text);
    printf("\033[0m");
}

void print_blue(const char *text) {
    printf("\033[0;34m");
    printf("%s", text);
    printf("\033[0m");
}

void print_purple(const char *text) {
    printf("\033[0;35m");
    printf("%s", text);
    printf("\033[0m");
}

void print_cyan(const char *text) {
    printf("\033[0;36m");
    printf("%s", text);
    printf("\033[0m");
}

void clear() {
    printf("\033[2J");
}

void todo() {
    print_red("Not implemented yet\n");
    exit(1);
}

void error(const char *text) {
    std::stringstream ss;
    ss << "[Error] " << text << "\n";
    print_red(ss.str().c_str());
    exit(1);
}

void warn(const char *text) {
    std::stringstream ss;
    ss << "[Warning] " << text << "\n";
    print_yellow(ss.str().c_str());
}

void info(const char *text) {
    std::stringstream ss;
    ss << "[Info] " << text << "\n";
    print_blue(ss.str().c_str());
}

void success(const char *text) {
    std::stringstream ss;
    ss << "[Success] " << text << "\n";
    print_green(ss.str().c_str());
}