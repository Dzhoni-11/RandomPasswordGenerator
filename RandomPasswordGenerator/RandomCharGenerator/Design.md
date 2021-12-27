# Random Password Generator

## Design

### Description
Random Password Generator is a console application which takes commands and arguments as input, and outputs a random password.

#### Definitions
|Name | Description
|-|-
|ASCII | abbreviated from American Standard Code for Information Interchange, is a character encoding standard for electronic communication


### Architecture
One class named RandCharGen generates random values based on ASCII table index.


Three ranges of importance from the ASCII table are Numerals, Special Characters, and Letters (Lower and Upper). [ASCII Table](https://www.asciitable.com/)
|Range |Index (ASCII) | size
|-|-|-
|Numbers |[48:57] |10
|Special |[[33:47]:[58:64]:[91:96]:[123:126] |32
|Letters |[[65:90]:[97:122]] |52

RandCharGen has 3 functions which populate a private instance container for later use.
 - LoadNumberRanges() - void of return
	 -  Access Private
 - LoadSpecialRanges() - void of return
	 - Access Private
 - LoadLetterRanges() - void of return
	 - Access Private

These 3 methods simply load the index of the significant characters into the container, final size of the container will be 94, allotted from the range sizes in table above.
Each LoadX() function has one parameter, of type vector for uint16_t.
- Parameter 1: vector<uint16_t> omitThese
	- Default: empty vector

LoadX() function body, loads values between their respective ranges and omit those passed by argument if any.
The container is a private instance variable of container type std::vector for stdint.h::uint8_t identified as m_AsciiRange.

Init() function makes calls to the LoadX() functions.
The Init() function has 5 parameters.

- Init() - void of return
	- - Accesss Public
	- Parameter 1: NumOfChars - uint8_t
		- Default: 4
	- Parameter 2: EnableSpecChars - bool
		- Default: true
	- Parameter 3: EnableNumChars - bool
		- Default: true
	- Parameter 4: EnableAlphaChars - bool
		- Default: true
	- Parameter 5: OmitTheseChars - string
		- Default: ""

Init function body stores the first argument by assigning its value to private instance variable of type uint8_t identified as m_SizeOfPassword.
Following is the conditional invocation of the the LoadX() functions, based on the 3 boolean arguments.
The fifth argument is used to range construct a vector<uint8_t> omit, this vector is passed as argument to the LoadX() functions.

Characters need to be generated, and this is done by GenrateChar() function.
- GenerateChar(void) - return vector containing uint8_t

Function body makes use of the following STD libraries
```
<ctime>        // std::time
<cstdlib>      // std::rand, std::srand
```
A new vector<uin8_t> is constructed with value in m_SizeOfPassword, identified as passwordSequence.

std::generate function is invoked, passing begin() and end iterators as first two arguments respectively. Third argument takes a generator function or class. A function named RandASCIIIndex is defined in anonymous namespace, and is passed as the third argument to generate.

The vector identified as passwordSequence is returned.

- RandASCIIIndex() - return uint8_t
Has one parameter:
- Parameter 1: MaxRange - uint8_t
returns random number from 0 to 93.

