#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <fstream>
#include <iostream>
#include <ctime>

namespace utils {
    // уровни логгирования
    enum class LEVELS {
        RELEASE,
        DEBUG
    };

    // оператор для вывода уровня логирования
    std::ostream& operator<< (std::ostream& out, LEVELS level) {
        switch (level) {
        case LEVELS::RELEASE:
            out << "RELEASE";
            break;
        case LEVELS::DEBUG:
            out << "DEBUG";
            break;
        default:
            out << "ERROR";
            break;
        }
        return out;
    }

    class logger {
    private:
        static std::ofstream m_out;
        static LEVELS m_level;
    public:

        // метод установки файла, куда будут записываться логи
        static void setFile(const std::string& fileName) { m_out.open(fileName); }

        // метод установки уровня логгирования 
        static void setLevel(LEVELS level) { m_level = level; }

        // метод записи
        static void write(const std::string& logText)
        {

            std::time_t current_time = std::time(nullptr);
            char currentTimeStr[30];
            std::strftime(currentTimeStr, sizeof(currentTimeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&current_time));

            if (!m_out.is_open())
                m_out.open("logs.txt");

            // при уровне DEBUG логи записываются и в консоль, и в файл
            if (m_level != LEVELS::RELEASE)
            {
                std::cout << "[" << currentTimeStr << "]"
                    << "[" << m_level << "]"
                    << " " << logText << std::endl;

                m_out << "[" << currentTimeStr << "]"
                    << "[" << m_level << "]"
                    << " " << logText << std::endl;

            }

            // при уровне RELEASE логи записываются только в файл
            if (m_level == LEVELS::RELEASE)
            {
                m_out << "[" << currentTimeStr << "]"
                    << "[" << m_level << "]"
                    << " " << logText << std::endl;
            }
        }


    };

    // статические поля класса logger
    std::ofstream logger::m_out;
    LEVELS logger::m_level = LEVELS::RELEASE;

}