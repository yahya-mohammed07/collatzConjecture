#include <iostream>
#include <vector>
// global vars
long global_steps = 0;
long global_largest = 0;
//
auto collatz (const long n) -> const std::vector<long>;
// driver code
auto main() -> int
{
    std::cout << "enter a number: ";
    long n = 0;
    std::cin >> n;
    //
    for (const auto& i: collatz(n))
    {
        std::cout << i << " ";
    }
    std::cout << '\n' << '\n';
    std::cout << "Steps: " << global_steps << '\n'
    << "Largest number: " << global_largest << std::endl;
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
            // else triple it  add 1 then divide it by 2
            vec.push_back((3 * vec.back()) + 1); // 3n + 1 / 2 for less steps
        }
        global_steps++;
        if (vec.back() > global_largest) global_largest = vec.back();
    }
    return vec;
}