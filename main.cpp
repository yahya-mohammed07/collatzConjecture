#include <iostream>
#include <vector>
// global vars
unsigned long g_steps = 0;
unsigned long long g_largest = 0;
//
auto collatz (const unsigned long long& n) -> const std::vector<unsigned long long>;
// driver code
auto main() -> int
{
    std::cout << "enter a number: ";
    unsigned long long n = 0;
    std::cin >> n;
    //
    for (const auto& i: collatz(n))
    {
        std::cout << i << " ";
    }
    std::cout << '\n' << '\n';
    std::cout << "Steps: " << g_steps << '\n'
    << "Largest number: " << g_largest << std::endl;
}
//
auto collatz (const unsigned long long& n) -> const std::vector<unsigned long long>
{
    std::vector<unsigned long long> vec;
    // added n to the vector vec
    vec.push_back(n);
    //check if the vec is not empty then check if the lastest element is 1 then stop
    while (!vec.empty() && vec.back() != 1)
    {
        // store the latest element to a void multiple calling
        unsigned long long latest = vec.back();
        // if the lastest element is even ...
        if (latest % 2 == 0)
        {
            // then divide it with 2
            vec.push_back(latest / 2);
        }
        else 
        {
            // else triple it  add 1 then divide it by 2
            vec.push_back((3 * latest) + 1); // 3n + 1 / 2 for less steps
        }
        g_steps++;
        if (latest > g_largest) g_largest = latest;
    }
    return vec;
}