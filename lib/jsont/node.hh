
#pragma once

#include <cstdint>
#include <memory>

#include <nlohmann/json.hpp>

#include <jsont/error.hh>
#include <jsont/deserializers/primitives.hh>


namespace jsont {


class json_node {

public:
	json_node(const std::string& document): _content(std::make_shared<json_node_value>(document)) { }

	template <typename T>
	T as() const {
		static_assert(is_json_deserializable<T>(), "Bad type for JSON deserialization");
		return json_deserialize_helper<T>::deserialize(_content);
	}


	template <typename T>
	T get(const uint32_t index) const {
		const json_node node = operator[](index);
		return node.as<T>();
	}

	template <typename T>
	T get(const std::string& key) const {
		const json_node node = operator[](key);
		return node.as<T>();
	}

	template <typename T>
	std::optional<T> get_opt(const std::string& key) const {
		if(!_content->data.is_object()) {
			throw _content->error("expected JSON object");
		}
		auto it = _content->data.find(key);
		if(it == _content->data.end() || it->is_null()) {
			return std::nullopt;
		}
		const json_node node = json_node(*it, _content, key);
		return node.as<T>();
	}


	json_node operator[](const uint32_t index) const {
		if(!_content->data.is_array()) {
			throw _content->error("expected JSON array");
		}
		if(index >= _content->data.size()) {
			throw _content->error("index too high for JSON array"); // TODO format
		}
		return json_node(_content->data.at(index), _content, index);
	}

	json_node operator[](const std::string& key) const {
		if(!_content->data.is_object()) {
			throw _content->error("expected JSON object");
		}
		auto it = _content->data.find(key);
		if(it == _content->data.end()) {
			throw _content->error("no value associated with key"); // TODO format
		}
		return json_node(*it, _content, key);
	}

	// iter()
	// entries()

	bool is_null()   const { return _content->data.is_null();            }
	bool is_bool()   const { return _content->data.is_boolean();         }
	bool is_number() const { return _content->data.is_number();          }
	bool is_int()    const { return _content->data.is_number_integer();  }
	bool is_uint()   const { return _content->data.is_number_unsigned(); }
	bool is_string() const { return _content->data.is_string();          }
	bool is_object() const { return _content->data.is_object();          }
	bool is_array()  const { return _content->data.is_array();           }

	// len
	// has_key

private:
	json_node(nlohmann::json val, std::shared_ptr<json_node_value> parent, uint32_t index): 
			_content(std::shared_ptr<json_node_value>(new json_node_value(val, parent, index))) { }

	json_node(nlohmann::json val, std::shared_ptr<json_node_value> parent, const std::string& key): 
			_content(std::shared_ptr<json_node_value>(new json_node_value(val, parent, key))) { }

	const std::shared_ptr<json_node_value> _content;

};


} // namespace jsont
