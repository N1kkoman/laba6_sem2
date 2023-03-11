#include <iostream>
#include "logger.h"

int main() {
    setlocale(LC_ALL, "rus");
    utils::logger::setFile("example.txt");
    utils::logger::setLevel(utils::LEVELS::RELEASE);
    utils::logger::write("этого примера не будет в консоли");
    utils::logger::setLevel(utils::LEVELS::DEBUG);
    utils::logger::write("пример");

    return 0;
}