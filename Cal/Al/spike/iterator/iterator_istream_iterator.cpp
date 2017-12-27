#include <iostream>
#include <iterator>

int main() {
    double value1, value2;
    std::cout << "Please input two values: ";

    // define the variable eos, donnot give value, then it can be judge condition
    std::istream_iterator<double> eos;
    std::istream_iterator<double> iit(std::cin);

    if(iit != eos)
        value1 = *iit;

    ++iit;
    if(eos != iit)
        value2 = *iit;

    std::cout << value1 << " * " << value2 << " = " << value1 * value2 << std::endl;
}
