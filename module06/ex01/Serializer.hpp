#pragma once
#include <iostream>
#include "stdint.h"

struct Data {
	int	id;
	std::string	name;
};

class Serializer {
	public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

	private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &rhs);
};
