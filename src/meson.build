
# Suggested directory layout :
#
# jsont_cpp
# │
# ├─ lib
# │  └─ jsont_cpp
# │     └─ utils.hh
# │
# └─ src
#    ├─ main.cc
#    └─ utils.cc


cpp_flags = [
  cpp_warning_flags,
  '-Wdisabled-optimization'
]

l_args = []


sources = [
	# 'utils.cc'
]

# headers_dir = include_directories('../lib')


executable('jsont-cpp', ['main.cc', sources], dependencies: [],
           cpp_args: [cpp_flags],
           link_args: [l_args],
#          include_directories: headers_dir,
           install: false,
           build_by_default: true)


# jsont_cpp_lib = static_library('jsont_cpp_static', sources, dependencies: [],
#                                         cpp_args: [cpp_flags],
#                                         link_args: [l_args],
#                                         include_directories: headers_dir,
#                                         install: false,
#                                         build_by_default: true)

# jsont_cpp_dep = declare_dependency(link_with : jsont_cpp_lib, 
#                                             include_directories : headers_dir)

