#pragma once

#include <iostream>
#include <memory>

#include "date.h"

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    Or,
    And,
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const std::string& event) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison cmp, const Date& date) : cmp_(cmp), date_(date) {}
    bool Evaluate(const Date& date, const std::string& event) const override;
private:
    Comparison cmp_;
    Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison cmp, const std::string& event) : cmp_(cmp), event_(event) {}
    bool Evaluate(const Date& date, const std::string& event) const override;
private:
    Comparison cmp_;
    std::string event_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(LogicalOperation op, std::shared_ptr<Node> left, std::shared_ptr<Node> right)
    : op_(op), left_(std::move(left)), right_(std::move(right)) {}
    bool Evaluate(const Date& date, const std::string& event) const override;
private:
    LogicalOperation op_;
    std::shared_ptr<Node> left_;
    std::shared_ptr<Node> right_;
};

