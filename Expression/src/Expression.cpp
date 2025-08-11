#include <Expression.hpp>

// ===== Number =====
Number::Number(double val) : value_{val} {}
double Number::evaluate() const{ return value_; }
void Number::print(std::ostream& os) const { os << value_;}
std::unique_ptr<Expression> Number::clone() const{
    return std::make_unique<Number>(value_);
}

// ===== BinaryOp =====
BinaryOp::BinaryOp(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right) : 
                                        left_{std::move(left)} , right_{std::move(right)} {} 


// ===== Helpers =====
std::unique_ptr<Expression> make_number(double value) {
    return std::make_unique<Number>(value);
}
