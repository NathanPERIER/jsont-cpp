
#pragma once

#include <string>
#include <exception>


namespace jsont {

class json_exception: public std::exception {

public:
	json_exception(const std::string& message): _message(message) { }

	const char* what() const noexcept {
		return _message.c_str();
	}

private:
	const std::string _message;

};

} // namespace jsont
