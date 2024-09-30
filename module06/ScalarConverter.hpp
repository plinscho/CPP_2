#pragma once
#include <iostream>

/*

Write a class ScalarConverter that will contain only one static methods "convert"
that will takes as parameter a string representation of a C++ literal in its most common
form and output its value in the following serie of scalar types :
• char
• int
• float
• double
As this class doesn’t need to store anything at all, this class must not be instanciable by
users.
Except for char parameters, only the decimal notation will be used.
Examples of char literals: ’c’, ’a’, ...
To make things simple, please note that non displayable characters shouldn’t be used as
inputs. If a conversion to char is not displayable, prints an informative message.
Examples of int literals: 0, -42, 42...
Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo literals as well (you know, for science): -inff, +inff
 
*/

class ScalarConverter {
	public:

	private:
	void	convert();

};
