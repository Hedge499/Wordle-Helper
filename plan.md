# Wordle Helper Plan

- [Wordle Helper Plan](#wordle-helper-plan)
- [Wordlist](#wordlist)
  - [Load Wordlist](#load-wordlist)
  - [Create Letter Count](#create-letter-count)
- [Words](#words)
  - [Potential Answer](#potential-answer)
  - [Best Next Words](#best-next-words)
- [Input](#input)
  - [Command Line](#command-line)
    - [Letter with Position in Word](#letter-with-position-in-word)
    - [Letter without Position in Word](#letter-without-position-in-word)
    - [Letter not in Word](#letter-not-in-word)
  - [Gui (Later)](#gui-later)

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

# Words

## Potential Answer

## Best Next Words

# Input

## Command Line

### Letter with Position in Word

### Letter without Position in Word

### Letter not in Word

## Gui (Later)