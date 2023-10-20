project('jsont', ['c','cpp'], default_options : ['cpp_std=gnu++2a'])


cpp_warning_flags = [
  '-Wall',
  '-Wextra',
  '-pedantic-errors',
  '-Wdisabled-optimization',
  '-Werror=unused-result'
]

nlohmann_json_proj = subproject('nlohmann_json')
nlohmann_json_dep = nlohmann_json_proj.get_variable('nlohmann_json_dep')


subdir('src')

subdir('tests')

