
#pragma once

#include <cstdint>
#include <memory>

#include <nlohmann/json.hpp>

#include <jsont/error.hh>



namespace jsont {

class json_node_value {

public:
	json_node_value(const std::string& document): parent(), index("."), data(nlohmann::json::parse(document)) { }

	json_exception error(const std::string& message) {
		return json_exception(message); // TODO format
	}

	const std::shared_ptr<json_node_value> parent;
	const std::string index;
	const nlohmann::json data;

private:
	json_node_value(nlohmann::json val, std::shared_ptr<json_node_value> parent, uint32_t index): 
			parent(parent), index("..."), data(val) { } // TODO format

	json_node_value(nlohmann::json val, std::shared_ptr<json_node_value> parent, const std::string& key): 
			parent(parent), index("..."), data(val) { } // TODO format

	friend class json_node;

};

} // namespace jsont