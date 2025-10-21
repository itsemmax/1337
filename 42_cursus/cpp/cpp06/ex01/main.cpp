#include "Serializer.hpp"

int main() {
	Data data = {9, "emma"};

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized pointer: " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data : " << deserializedData->a << ", str: " << deserializedData->str << std::endl;

	if(&data == deserializedData)
		std::cout << "Success" << std::endl;
	else
		std::cout << "Error" << std::endl;

	return 0;
}