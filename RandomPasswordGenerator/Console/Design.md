# Console

## Design

### Description

Console Class serves as the argument parser for supported commands in the list below.

Supported Commands stem from Random Password Generator Requirements. The Commands are listed below.
| Cmd| Value| Description |
| -| -|-
|"\l"| (unsigned)|Sets the Password Length to integer succeeding this command. Minimum: 4. Maximum: 16. Example: "\l 11".
| "\s"| (bool)| Enable (1) or Disable (0) Special Characters from the generated password. i.e. {~, *, ^} etc. Enable: 1. Disable: 0. Example: "\s 0".
| "\n"| (bool)| Enable (1) or Disable (0) Numeral Characters from the generated password. i.e. {1, 2, 3} etc. Enable: 1. Disable: 0. Example: "\n 0".
| "\a"| (bool)| Enable (1) or Disable (0) Alphabet Characters from the generated password. i.e. {a, z, G} etc. Enable: 1 Disable: 0. Example: "\a 0".
| "\o"| (char) []| Omit the given list of characters from generated password. Example: "\o _ @ 3 K ` ) ( ; ,".

### Architecture

Console is a Class which has one basic behavior implemented by the following function;

>### ParseArgs (int, int* [], RandomPaswordStruct&) return void
> First parameter identifies as **argc** whose type is int which contains the size of next argument.
> Second parameter identifies as **argv** is a pointer to a list which contains the arguments to be parsed for commands.
> Third parameter identifies as **st** is a reference to a user defined type, which contains instance variables to store the values of command.
>>#### Behavior
>> Iterates through the **arv** list and makes consecutive calls to private function **SearchCommand()** which is passed the current argument and a stored c-string for the expected argument. If SearchCommand() returns true, the argument was found, and its consecutive value is stored in the reference variable **st**.
>> Once all argv have been iterated upon, the function returns with the reference variable **st** populated.

