
#pragma once

#include <cstdint>
#include <string>

#include <jsont/deserializers/base.hh>


namespace jsont {

template <>
struct json_deserialize_helper<bool> {
	static constexpr bool can_deserialize = true;
	static bool deserialize(std::shared_ptr<json_node_value> json) {
		if(!json->data.is_boolean()) {
			throw json_exception("expected a boolean value");
		}
		return json->data.get<bool>();
	}
};


template <>
struct json_deserialize_helper<float> {
	static constexpr bool can_deserialize = true;
	static float deserialize(std::shared_ptr<json_node_value> json) {
		if(!json->data.is_number()) {
			throw json_exception("expected a numeric value");
		}
		return json->data.get<float>();
	}
};

template <>
struct json_deserialize_helper<double> {
	static constexpr bool can_deserialize = true;
	static double deserialize(std::shared_ptr<json_node_value> json) {
		if(!json->data.is_number()) {
			throw json_exception("expected a numeric value");
		}
		return json->data.get<double>();
	}
};


template <>
struct json_deserialize_helper<int64_t> {
	static constexpr bool can_deserialize = true;
	static int64_t deserialize(std::shared_ptr<json_node_value> json) {
		if(!json->data.is_number_integer()) {
			throw json_exception("expected an integer value");
		}
		return json->data.get<int64_t>();
	}
};

template <>
struct json_deserialize_helper<uint64_t> {
	static constexpr bool can_deserialize = true;
	static uint64_t deserialize(std::shared_ptr<json_node_value> json) {
		if(!json->data.is_number_unsigned()) {
			throw json_exception("expected an unsigned integer value");
		}
		return json->data.get<uint64_t>();
	}
};


template <>
struct json_deserialize_helper<std::string> {
	static constexpr bool can_deserialize = true;
	static std::string deserialize(std::shared_ptr<json_node_value> json) {
		if(!json->data.is_string()) {
			throw json_exception("expected a string value");
		}
		return json->data.get<std::string>();
	}
};

} // namespace jsont
