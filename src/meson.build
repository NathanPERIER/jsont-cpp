
cpp_flags = [
  cpp_warning_flags,
  '-Wdisabled-optimization'
]

l_args = []


sources = [
	# 'utils.cc'
]

headers_dir = include_directories('../lib')


# jsont_lib = static_library('jsont_static', sources, dependencies: [nlohmann_json_proj],
#                            cpp_args: [cpp_flags],
#                            link_args: [l_args],
#                            include_directories: headers_dir,
#                            install: false,
#                            build_by_default: true)

jsont_dep = declare_dependency(include_directories: headers_dir, dependencies: [nlohmann_json_dep])
# link_with : jsont_lib ?
