
#pragma once

#include <optional>

#include <jsont/value.hh>
#include <jsont/error.hh>


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


template <typename T>
struct json_deserialize_helper<std::optional<T>> {
	static constexpr bool can_deserialize = is_json_deserializable<T>();
	static std::optional<T> deserialize(std::shared_ptr<json_node_value> json) {
		if(json->data.is_null()) {
			return std::nullopt;
		}
		return std::optional<T>(json_deserialize_helper<T>::deserialize(json));
	}
};

} // namespace jsont

