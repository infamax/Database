#include "node.h"

bool EmptyNode::Evaluate(const Date &date, const std::string &event) const {
    return true;
}

bool DateComparisonNode::Evaluate(const Date &date, const std::string &event) const {
    if (cmp_ == Comparison::Less) {
        return date < date_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return date <= date_;
    } else if (cmp_ == Comparison::Greater) {
        return date > date_;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return date >= date_;
    } else if (cmp_ == Comparison::Equal) {
        return date_ == date;
    }
    return date_ != date;
}

bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) const {
    if (cmp_ == Comparison::Less) {
        return event < event_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return event <= event_;
    } else if (cmp_ == Comparison::Greater) {
        return event > event_;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return event >= event_;
    } else if (cmp_ == Comparison::Equal) {
        return event == event_;
    }
    return event_ != event;
}

bool LogicalOperationNode::Evaluate(const Date &date, const std::string &event) const {
    if (op_ == LogicalOperation::Or) {
        return (left_->Evaluate(date, event)) || (right_->Evaluate(date, event));
    }
    return (left_->Evaluate(date, event)) && (right_->Evaluate(date, event));
}