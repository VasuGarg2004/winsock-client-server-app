#include <iostream>
#include <string>

int server();
int client(const char* server_name);

int main(int argc, char** argv) {
	std::string server_name;

	// validate parameters input
	if (argc != 2 || (strcmp(argv[1], "server") != 0 && strcmp(argv[1], "client") != 0)) {
		std::cout << "usage: " << argv[0] << " server/client" << std::endl;
		std::cout << "server eval: " << (argv[1] != "server") << std::endl;
		std::cout << "client eval: " << (argv[1] != "client") << std::endl;
		return 1;
	}

	std::cout << "passed validation" << std::endl;

	if (strcmp(argv[1], "server") == 0) {
		server();
	}

	if (strcmp(argv[1], "client") == 0) {
		std::cout << "server name: ";
		std::getline(std::cin, server_name);
		client(server_name.c_str());
	}

	return 0;
}