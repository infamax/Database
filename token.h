#pragma once

#include <sstream>
#include <vector>
using namespace std;

enum class TokenType {
    DATE, // Дата
    EVENT, // Событие
    COLUMN, // Тип колонки дата или событие
    LOGICAL_OP, // Логическая операция
    COMPARE_OP, // Операция сравнения
    PAREN_LEFT, // Левая скобка
    PAREN_RIGHT, // Правый скобка
};

struct Token {
    const string value;
    const TokenType type;
};

vector<Token> Tokenize(istream& cl);