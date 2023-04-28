#include "list.hpp"
#include <list>
#include <string>
#include <iostream>

// overload << Operator for easy list printing
std::ostream &operator<<(std::ostream &os, const std::list<std::string> &list)
{
    for (auto const &i : list)
    {
        os << i << "\n";
    }
    return os;
}
std::ostream &operator<<(std::ostream &os, const std::list<char> &list)
{
    for (auto const &i : list)
    {
        os << i << "\n";
    }
    return os;
}

// overload << Operator for easy map printing
std::ostream &operator<<(std::ostream &os, const std::map<char, int> &map)
{
    for (auto const &[key, val] : map)
    {
        os << key << " " << val << "\n";
    }
    return os;
}

int main()
{
    std::list<std::string> wordlist{loadWordlistFromFile()};
    std::map<char, int> lettersWithPosition{{'a', 2}, {'b', 3}};
    std::list<char> lettersWithoutPosition{'d', 'e'};
    std::list<char> lettersNotInWord{'s'};
    bool running{true};

    while (running)
    {
        std::cout << "Known information:\n"
                  << "Letters that are in the word and their Position:\n"
                  << lettersWithPosition
                  << "Letters that are in the word without Position:\n"
                  << lettersWithoutPosition
                  << "Letters that are not in the word\n"
                  << lettersNotInWord
                  << "\n"
                  << "Next action?\n"
                  << "1) show potential answers\n"
                  << "2) show good next words\n"
                  << "3) add new information\n"
                  << "4) exit\n"
                  << "Choose by entering a number: ";

        int choice{0};
        std::cin >> choice;
        switch (choice)
        {
        case 1:

            break;

        default:
            break;
        }

        running = false;
    }

    return 0;
}