# Wordle Helper Plan

- [Wordle Helper Plan](#wordle-helper-plan)
- [Wordlist](#wordlist)
  - [Load Wordlist](#load-wordlist)
  - [Create Letter Count](#create-letter-count)
- [wordle](#wordle)
  - [Answer](#answer)
  - [next Word](#next-word)
- [main](#main)
  - [add information](#add-information)
  - [exit](#exit)
  - [Variables](#variables)
  - [Loop](#loop)

# Wordlist

A wordlist containing 479k English words from https://github.com/dwyl/english-words is used as a base to calculate/find the best words to use, and find the potential answers. The list is filtered to only contain 5 letter words, since wordle only accepts those. Still 15920 words left. Some seem to be gibberish.

## Load Wordlist

- header: returns `list`, no parameter 
- open file
- `readline()`
- append into a list
- close file
- return list

## Create Letter Count

- header: returns `map<letter, count>`, params: List of words
- iterate through list
- iterate through each string 
- add +1 for each letter in the word to the map
- return map

# wordle

## Answer

- header: returns void, params: letters with position in word, letters without position in word, letters not in word and the wordlist
- filter Wordlist
- print remaining list 

## next Word

- header: return void, params: letters with position in word, letters without position in word, letters not in word and the wordlist
- variables:
  - top 3 words
- create count [map](#create-letter-count) with wordlist
- iterate through wordlist
- give each word a value and save them in a variable if the value is higher than any value of the previous saved word
  - letter with know position in word `value * 0`
  - letter not in word `value * 0`
  - letter in word without position `value * 0.5`
  - other `value * 1`
- print the 3 words saved in variables with the highest calculated values

# main

## add information

- letters with position in word
- letters without position in word
- letters not in word
  
## exit

set boolean to false &rarr; while loop ends.

## Variables

- List wordlist: containing wordlist
- map lettersWithPosition: containing letters with position in word
- List lettersWithoutPosition: containing letters without position in word
- List lettersNotInWord: containing letters not in word
- Boolean running: keep program(while loop) running till exit

## Loop

1. print known info from above [variables](#variables)
2. prompt the choices: 
   1. [answer](#answer)
   2. [next Word](#next-word)
   3. [add info](#add-information)
   4. [exit](#exit)
3. ask input from 1 - 4
4. run specified function