#pragma once //Expression.hpp
#include <memory>
#include <vector>
#include <memory>
#include <utility>
#include <cassert>
#include <iostream>

// ===== Expression =====
class Expression{
public:
    virtual ~Expression() = default;
    virtual double evaluate() const = 0;
    virtual void print(std::ostream&) const = 0;  
    virtual std::unique_ptr<Expression> clone() const = 0; 
};

// ===== Number =====
class Number : public Expression{
private:
    double value_;
public:
    Number(double val);

    double evaluate() const override;
    void print(std::ostream&) const override;
    std::unique_ptr<Expression> clone() const override;
};

// ===== BinaryOp =====
class BinaryOp : public Expression {
protected:
    std::unique_ptr<Expression> left_;
    std::unique_ptr<Expression> right_;
public:
    BinaryOp(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
};

class NaryOp : public Expression{ 
protected:
    std::vector<std::unique_ptr<Expression>> operands_;
public:
    template <typename... Args>
    NaryOp(Args&&... args);
};

// ===== IsNary =====
template <typename... Args>
class IsNary : public std::bool_constant<(sizeof...(Args) > 2)> {};

// ===== Addition =====

template <bool>
class AdditionHelp : public BinaryOp {
public:
    using BinaryOp::BinaryOp;

    double evaluate() const override;
    void print(std::ostream&) const override;
    std::unique_ptr<Expression> clone() const override;
};

template <>
class AdditionHelp<true> : public NaryOp {
public:
    using NaryOp::NaryOp;

    double evaluate() const override;
    void print(std::ostream&) const override;
    std::unique_ptr<Expression> clone() const override;
};

template <typename... Args>
class Addition : public AdditionHelp<IsNary<Args...>::value>{
    using Base = AdditionHelp<IsNary<Args...>::value>;
public:
    Addition(Args&&... args); 
};

template <typename... Args>
Addition(Args&&... args) -> Addition<Args...>;

// ===== Subtraction =====

template <bool>
class SubtractionHelp : public BinaryOp {
public:
    using BinaryOp::BinaryOp;

    double evaluate() const override;
    void print(std::ostream&) const override;
    std::unique_ptr<Expression> clone() const override;
};

template <>
class SubtractionHelp<true> : public NaryOp {
public:
    using NaryOp::NaryOp;

    double evaluate() const override;
    void print(std::ostream&) const override;
    std::unique_ptr<Expression> clone() const override;
};

template <typename... Args>
class Subtraction : public SubtractionHelp<IsNary<Args...>::value>{
    using Base = SubtractionHelp<IsNary<Args...>::value>;
public:
    Subtraction(Args&&... args); 
};

template <typename... Args>
Subtraction(Args&&... args) -> Subtraction<Args...>;

// ===== Multiplication =====

template <bool>
class MultiplicationHelp : public BinaryOp {
public:
    using BinaryOp::BinaryOp;

    double evaluate() const override;
    void print(std::ostream&) const override;
    std::unique_ptr<Expression> clone() const override;
};

template <>
class MultiplicationHelp<true> : public NaryOp {
public:
    using NaryOp::NaryOp;

    double evaluate() const override;
    void print(std::ostream&) const override;
    std::unique_ptr<Expression> clone() const override;
};

template <typename... Args>
class Multiplication : public MultiplicationHelp<IsNary<Args...>::value>{
    using Base = MultiplicationHelp<IsNary<Args...>::value>;
public:
    Multiplication(Args&&... args); 
};

template <typename... Args>
Multiplication(Args&&... args) -> Multiplication<Args...>;

// ===== Helpers =====

template <typename... Args>
std::unique_ptr<Expression> make_addition(Args&&... args);

template <typename... Args>
std::unique_ptr<Expression> make_subtraction(Args&&... args);

template <typename... Args>
std::unique_ptr<Expression> make_multiplication(Args&&... args);


std::unique_ptr<Expression> make_number(double args);


#include "Expression.tpp"