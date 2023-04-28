#include "list.hpp"
#include "wordle.hpp"
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
        os << "Letter " << key << " at the position " << val << ".\n";
    }
    return os;
}

int main()
{
    std::list<std::string> wordlist{loadWordlistFromFile()};
    std::map<char, int> lettersWithPosition{{'a', 2}, {'b', 3}};
    std::list<char> lettersWithoutPosition{'i', 'o'};
    std::list<char> lettersNotInWord{'s'};
    bool running{true};

    while (running)
    {
        std::cout << "Known information:\n"
                  << "Letters that are in the word and their Position(0-4):\n"
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
                  << "4) erase information\n"
                  << "5) exit\n"
                  << "Choose by entering a number(1-5): ";

        int choice{0};
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << getAnswer(lettersWithPosition, lettersWithoutPosition, lettersNotInWord, wordlist) << "\n";
            break;
        case 2:
            std::cout << nextWords(lettersWithPosition, lettersWithoutPosition, lettersNotInWord, wordlist) << "\n";
            break;
        case 3:
            break;
        case 4:
            lettersWithPosition.clear();
            lettersWithoutPosition.clear();
            lettersNotInWord.clear();
            break;
        case 5:
            running = false;
            break;
        default:
            std::cout << "Not a valid input!!!\n";
            break;
        }
    }

    return 0;
}