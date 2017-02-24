#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

void my_cout(const int number)
{ std::cout << ' ' << number; }

int main()
{
    const int loop{10};
    assert(loop > 0);

    std::vector <int> seque_a;

    seque_a.push_back(2);

    int count = 1;

    while (count < loop)
    {
        seque_a.push_back(-seque_a[count - 1]*seque_a[count - 1]*seque_a[count - 1] - 3);
        ++count;
    }
    /// Made a simple variable vector with differentiable members.

    assert(seque_a.size() == loop);
    /// Assure the vector size is right.

    /// The for_each algorithm: (start position, end position, function for the members)
    std::cout << '[';
    std::for_each(std::begin(seque_a),
                  std::end(seque_a),
                  [](const int i) { std::cout << i << ' '; });
    std::cout << "]\n";

    /// The range based for loop
    std::cout << '(';
    for (int number : seque_a)
    { std::cout << ' ' << number;}
    std::cout << ")\n";

    /// The variable based for loop
    std::cout << '{';
    for (int iter{0}; iter < static_cast<int>(seque_a.size()); ++iter)
    { std::cout << ' ' << seque_a[iter];}
    std::cout << "}\n";

    std::vector <int> seque_b(loop, 0);
    /// Please initialize your simple variable vectors if possible.

    std::cout << '{';
    std::for_each(std::begin(seque_b),
                  std::end(seque_b),
                  [](const int i) { std::cout << i << ' '; });
    std::cout << "}\n";

    /// Full copying of a vector to another vector of the same size
    std::copy(seque_a.begin(), seque_a.end(), seque_b.begin());
    /// This can be done for smaller ranges and with different positions.

    std::cout << '[';
    std::for_each(std::begin(seque_b),
                  std::end(seque_b),
                  [](const int i) { std::cout << i << ' '; });
    std::cout << "]\n";

    std::vector <int> seque_c(7, 0);

    std::cout << '{';
    std::for_each(std::begin(seque_c),
                  std::end(seque_c),
                  [](const int i) { std::cout << i << ' '; });
    std::cout << "}\n";

    /// Partial copying, would be a pain with a variable based for loop.
    std::copy(std::begin(seque_b) + 2, std::begin(seque_b) + 5, std::begin(seque_c) + 1);

    std::cout << '[';
    std::for_each(std::begin(seque_c),
                  std::end(seque_c),
                  [](const int i) { std::cout << i << ' '; });
    std::cout << "]\n";

    /// Sorting part of a vector
    std::sort(std::begin(seque_b) + 2, std::end(seque_b) - 2);

    std::cout << '{';
    std::for_each(std::begin(seque_b),
                  std::end(seque_b),
                  [](const int i) { std::cout << i << ' '; });
    std::cout << "}\n";

    /// Sorting the whole vector
    std::sort(std::begin(seque_b), std::end(seque_b));

    std::cout << '[';
    std::for_each(std::begin(seque_b),
                  std::end(seque_b),
                  [](const int i) { std::cout << i << ' '; });
    std::cout << "]\n";

    return 0;
}
