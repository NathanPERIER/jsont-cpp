
cpp_flags = [
  cpp_warning_flags,
  '-Wdisabled-optimization'
]

l_args = []


sources = [
	# 'utils.cc'
]

headers_dir = include_directories('../lib')


executable('jsont-cpp', ['main.cc', sources], dependencies: [],
           cpp_args: [cpp_flags],
           link_args: [l_args],
           include_directories: headers_dir,
           install: false,
           build_by_default: true)


# jsont_lib = static_library('jsont_static', sources, dependencies: [],
#                            cpp_args: [cpp_flags],
#                            link_args: [l_args],
#                            include_directories: headers_dir,
#                            install: false,
#                            build_by_default: true)

jsont_dep = declare_dependency(include_directories : headers_dir)
# link_with : jsont_lib ?
