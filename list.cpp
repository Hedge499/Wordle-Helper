#include "list.hpp"
#include <fstream>
#include <regex>

// trims whitespace from the beginning and end of str
std::string trim(std::string str)
{
    return std::regex_replace(str, std::regex("^\\s+ | \\s+$"), std::string{""});
}

// read the wordlist.txt from the resource folder line by line.
// returns a List of words.
std::list<std::string> loadWordlistFromFile()
{
    std::list<std::string> wordlist{};

    std::ifstream wordlistFile("wordlist.txt");
    std::string line{};
    while (std::getline(wordlistFile, line))
    {
        wordlist.push_back(trim(line));
    }

    return wordlist;
}

// iterates through a list of words and counts the letters.
// returns a map with a letter as key and the count as value.
std::map<char, int> createLetterCount(std::list<std::string> wordlist)
{
    std::map<char, int> letterCount{};

    for (std::string str : wordlist)
    {
        for (char c : str)
        {
            letterCount[c]++;
        }
    }

    return letterCount;
}