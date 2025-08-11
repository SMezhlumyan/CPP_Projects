#include <Expression.hpp>


bool almost_equal(double a, double b, double epsilon = 1e-9) {
    return std::abs(a - b) < epsilon;
}

void test_expr(const std::unique_ptr<Expression>& expr, double expected_result, const char* test_name) {
    std::cout << test_name << ": ";
    expr->print(std::cout);
    double result = expr->evaluate();
    std::cout << " = " << result << std::endl;
    assert(almost_equal(result, expected_result) && "Test failed: result does not match expected value");
}

int main() {
    {
        auto expr = make_addition(
            make_number(3),
            make_number(5)
        );
        test_expr(expr, 8.0, "Test 1");
    }

    {
        auto expr = make_addition(
            make_number(3),
            make_multiplication(
                make_number(4),
                make_subtraction(
                    make_number(2),
                    make_number(1)
                )
            )
        );
        test_expr(expr, 7.0, "Test 2");
    }

    {
        auto expr = make_multiplication(
            make_number(2),
            make_number(3),
            make_number(4)
        );
        test_expr(expr, 24.0, "Test 3");
    }

    {
        auto expr = make_subtraction(
            make_number(10),
            make_number(2),
            make_number(3)
        );
        test_expr(expr, 5.0, "Test 4");
    }

    {
        auto expr = make_multiplication(
            make_addition(make_number(5), make_number(2)),
            make_subtraction(make_number(10), make_number(3))
        );
        std::cout << "Test 5: ";
        expr->print(std::cout);
        double result = expr->evaluate();
        std::cout << " = " << result << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
