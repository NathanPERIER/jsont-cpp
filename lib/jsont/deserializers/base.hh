
#pragma once

#include <jsont/value.hh>


namespace jsont {

template <typename T>
struct json_deserialize_helper {
	static constexpr bool can_deserialize = false;
	static T deserialize(std::shared_ptr<json_node_value> json); 
};

template <typename T>
constexpr bool is_json_deserializable() {
	return json_deserialize_helper<T>::can_deserialize;
}

} // namespace jsont

