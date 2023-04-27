#include "wordle.hpp"

// creates a list of answers for a wordle round based on the given information
// the more information the less potential answers
// returns a list of answers
std::list<std::string> getAnswer(std::map<char, int> lettersWithPosition, std::list<char> lettersWithoutPosition, std::list<char> lettersNotInWord, std::list<std::string> wordlist)
{
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