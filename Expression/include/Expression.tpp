//Expression.tpp
#include "Expression.hpp"
template <typename... Args>
NaryOp::NaryOp(Args&&... args){
            (operands_.emplace_back(std::forward<Args>(args)), ...);
}

// ===== AdditionHelp =====
template <bool B>
inline double AdditionHelp<B>::evaluate() const {
    return left_->evaluate() + right_->evaluate();
}

template <bool B>
inline void AdditionHelp<B>::print(std::ostream& os) const {
    os << "(";
    left_->print(os);
    os << " + ";
    right_->print(os);
    os << ")";
}
template <bool B>
inline std::unique_ptr<Expression> AdditionHelp<B>::clone() const {
    return std::make_unique<AdditionHelp<B>>(left_->clone(), right_->clone());
}

inline double AdditionHelp<true>::evaluate() const {
    double sum = 0;
    for (const auto& op : operands_) {
        sum += op->evaluate();
    }
    return sum;
}

inline void AdditionHelp<true>::print(std::ostream& os) const {
    os << "(";
    for (size_t i = 0; i < operands_.size(); ++i) {
        operands_[i]->print(os);
        if (i + 1 < operands_.size()) os << " + ";
    }
    os << ")";
}
inline std::unique_ptr<Expression> AdditionHelp<true>::clone() const {
    std::vector<std::unique_ptr<Expression>> copy_operands;

    for (const auto& op : operands_)
    {
        copy_operands.push_back(op->clone());
    }
    auto copyAdd = std::make_unique<AdditionHelp<true>>();
    copyAdd->operands_ = std::move(copy_operands);
    return copyAdd;

}

template <typename... Args>
inline Addition<Args...>::Addition(Args&&... args)
    : Base(std::forward<Args>(args)...) {}

// ===== Subtraction =====
template <bool B>
inline double SubtractionHelp<B>::evaluate() const {
    return left_->evaluate() - right_->evaluate();
}

template <bool B>
inline void SubtractionHelp<B>::print(std::ostream& os) const {
    os << "(";
    left_->print(os);
    os << " - ";
    right_->print(os);
    os << ")";
}
template <bool B>
inline std::unique_ptr<Expression> SubtractionHelp<B>::clone() const {
    return std::make_unique<SubtractionHelp<B>>(left_->clone(), right_->clone());
}

inline double SubtractionHelp<true>::evaluate() const {
    double result = operands_[0]->evaluate();
    for (size_t i = 1; i < operands_.size(); ++i) {
        result -= operands_[i]->evaluate();
    }
    return result;
}

inline void SubtractionHelp<true>::print(std::ostream& os) const {
    os << "(";
    for (size_t i = 0; i < operands_.size(); ++i) {
        operands_[i]->print(os);
        if (i + 1 < operands_.size()) os << " - ";
    }
    os << ")";
}
inline std::unique_ptr<Expression> SubtractionHelp<true>::clone() const {
    std::vector<std::unique_ptr<Expression>> copy_operands;

    for (const auto& op : operands_)
    {
        copy_operands.push_back(op->clone());
    }
    auto copySub = std::make_unique<SubtractionHelp<true>>();
    copySub->operands_ = std::move(copy_operands);
    return copySub;

}

template <typename... Args>
inline Subtraction<Args...>::Subtraction(Args&&... args): 
        Base(std::forward<Args>(args)...){}

// ===== Multiplication =====
template <bool B>
inline double MultiplicationHelp<B>::evaluate() const{
    return left_->evaluate() * right_->evaluate();
}  

template <bool B>
inline void MultiplicationHelp<B>::print(std::ostream& os) const{
    os << "(";
    left_->print(os);
    os << " * ";
    right_->print(os);
    os << ")";
}
template <bool B>
inline std::unique_ptr<Expression> MultiplicationHelp<B>::clone() const {
    return std::make_unique<MultiplicationHelp<B>>(left_->clone(),right_->clone());
}

inline double MultiplicationHelp<true>::evaluate() const{
    double sum = 1.0;
    for (const auto& op : operands_) {
        sum *= op->evaluate();
    }
    return sum;
}

inline std::unique_ptr<Expression> MultiplicationHelp<true>::clone() const {
    std::vector<std::unique_ptr<Expression>> copy_operands;

    for(const auto& op : operands_){
        copy_operands.push_back(op->clone());
    }

    auto copyMult = std::make_unique<MultiplicationHelp<true>>();
    copyMult->operands_ = std::move(copy_operands);
    return copyMult;
}

inline void MultiplicationHelp<true>::print(std::ostream& os) const{
    os << "(";
    for (size_t i = 0; i < operands_.size(); ++i) {
        operands_[i]->print(os);
        if (i + 1 < operands_.size()) os << " * ";
    }
    os << ")";
}

template <typename... Args>
inline Multiplication<Args...>::Multiplication(Args&&... args): 
        Base(std::forward<Args>(args)...){}

// ===== Helpers =====

template <typename... Args>
std::unique_ptr<Expression> make_addition(Args&&... args) {
    return std::make_unique<Addition<Args...>>(std::forward<Args>(args)...);
}

template <typename... Args>
std::unique_ptr<Expression> make_subtraction(Args&&... args) {
    return std::make_unique<Subtraction<Args...>>(std::forward<Args>(args)...);
}

template <typename... Args>
std::unique_ptr<Expression> make_multiplication(Args&&... args) {
    return std::make_unique<Multiplication<Args...>>(std::forward<Args>(args)...);
}

