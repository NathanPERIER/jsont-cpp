
#include <iostream>

#include <jsont/node.hh>

int main(int argc, char** argv) {
	// std::string s = jsont::json_node("{\"valu\": \"lol\"}")["value"].as<std::string>();
	// std::string s = jsont::json_node("{\"value\": \"lol\"}").get_opt<std::string>("valu").value_or("null");
	std::string s = jsont::json_node("[\"value\", \"lol\"]").get<std::string>(1);

	std::cout << s << std::endl;

	return 0;
}

