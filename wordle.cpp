#include "wordle.hpp"
#include <algorithm>

// creates a list of answers for a wordle round based on the given information
// the more information the less potential answers
// returns a list of answers
std::list<std::string> getAnswer(std::map<char, int> lettersWithPosition, std::list<char> lettersWithoutPosition, std::list<char> lettersNotInWord, std::list<std::string> wordlist)
{
    // all words that can be the answer to the wordle quiz
    std::list<std::string> answers{};

    // filter out words that can not be the answer
    for (std::string const word : wordlist)
    {
        // is the word still viable as an answer
        bool fit{true};

        // check wether the word has the right letters at the right position
        for (auto const &[letter, pos] : lettersWithPosition)
        {
            if (word[pos] != letter)
            {
                fit = false;
                break;
            }
        }

        // if the word is still a viable answer, check if the word contains all the necessary letters.
        if (fit)
        {
            for (char const &letter : lettersWithoutPosition)
            {
                if (std::find(word.begin(), word.end(), letter) == word.end())
                {
                    fit = false;
                    break;
                }
            }

            // if the word is still a viable answer, check that the word does not contain any letters that are not in the answer.
            if (fit)
            {
                for (char const &letter : lettersNotInWord)
                {
                    if (std::find(word.begin(), word.end(), letter) != word.end())
                    {
                        fit = false;
                        break;
                    }
                }

                // if the word is still a viable answer, push the word into the answer list
                if (fit)
                {
                    answers.push_back(word);
                }
            }
        }
    }

    return answers;
}

// chooses three words a best next word in an wordle round
// 1. determining the value of each word by counting the occurrences in the wordlist
// 2. iterate through the wordlist and determine the value of each word
// 2a. each letter which is not in the word or is in the word and the position is know has no value (0 * the value of the letter)
// 2b. each letter which is in the word but the position is not known has half its value (0.5 * the value of the letter)
// 2c. each letter which we have no information about has its full value (1 * value of the letter)
// 3. save the 3 words with the highest value
// returns a list of 3 good next words
std::list<std::string> nextWords(std::map<char, int> lettersWithPosition, std::list<char> lettersWithoutPosition, std::list<char> lettersNotInWord, std::list<std::string> wordlist)
{
}