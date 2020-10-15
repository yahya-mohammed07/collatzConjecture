#include <iostream>
#include <vector>

auto collatz (const long n) -> const std::vector<long>;
// driver code
auto main() -> int
{
    std::cout << "enter a number: ";
    long n = 0;
    std::cin >> n;
    //
    for (const auto i: collatz(n))
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
//
auto collatz (const long n) -> const std::vector<long>
{
    std::vector<long> vec;
    // added n to the vector vec
    vec.push_back(n);
    //check if the vec is not empty then check if the lastest element is 1 then stop
    while (!vec.empty() && vec.back() != 1)
    {
        // if the lastest element is even ...
        if (vec.back() % 2 == 0)
        {
            // then divide it with 2
            vec.push_back(vec.back() / 2);
        }
        else 
        {
            // else triple it then add 1
            vec.push_back((3 * vec.back()) + 1);
        }
    }
    return vec;
}