#include <iostream>
#include "logger.h"

int main() {
    setlocale(LC_ALL, "rus");
    utils::logger::setFile("example.txt");
    utils::logger::write("этот пример не отобразится");
    utils::logger::setLevel(utils::LEVELS::DEBUG);
    utils::logger::write("пример1");
    utils::logger::setLevel(utils::LEVELS::INFO);
    utils::logger::write("пример2");

    return 0;
}
