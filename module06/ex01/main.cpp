#include "Serializer.hpp"
#include <iostream>

int main() {
	Data originalData;
	originalData.id = 42;
	originalData.name = "Test Data";

	// Serialize the pointer to originalData
	uintptr_t raw = Serializer::serialize(&originalData);

	// Deserialize the raw value back to a Data pointer
	Data* deserializedData = Serializer::deserialize(raw);

	// Verify that the deserialized pointer is equal to the original pointer
	if (deserializedData == &originalData) {
		std::cout << "Serialization and deserialization successful!" << std::endl;
		std::cout << "ID: " << deserializedData->id << ", Name: " << deserializedData->name << std::endl;
	} else {
		std::cout << "Serialization and deserialization failed!" << std::endl;
	}

	return 0;
}