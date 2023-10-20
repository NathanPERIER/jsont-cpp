
# JSON't CPP

## Build

### Setup

#### 1. Clone the repository

```bash
git clone git@github.com:NathanPERIER/jsont-cpp.git
cd jsont-cpp
```

#### 2. Download subprojects

```bash
meson subprojects download
```

#### 3. Create the build directories

```bash
meson setup build_debug --buildtype=debug
meson setup build_optim --buildtype=debugoptimised
meson setup build_release --buildtype=release
```

### Compilation

```bash
cd build_debug
# default targets
ninja
# specific target
ninja tests/jsont_cpp
```

### Run

```bash
src/jsont_cpp
tests/jsont_cpp
```

## Include as a subproject

### Basic sample wrap file

```
[wrap-git]
url = https://github.com/NathanPERIER/jsont-cpp.git
revision = master
depth = 1

[provide]
jsont_cpp_dep = jsont_cpp_static
```

> For more information, please check [the Meson documentation](https://mesonbuild.com/Wrap-dependency-system-manual.html).

### Retrieving a dependency

```
jsont_cpp_dep = find_dependency('jsont_cpp')
```

> Note that the subproject will **not** be used if there is already a `jsont_cpp` library detectable via `find_package` on the system

### Retrieving a variable

```
jsont_cpp_proj = subproject('jsont_cpp_static')
jsont_cpp_var = jsont_cpp_proj.variable('var')
# Another way of retrieving a dependency, bypassing potential libraries already installed on the system
jsont_cpp_dep = jsont_cpp_proj.variable('jsont_cpp_dep')
```

