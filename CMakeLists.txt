cmake_minimum_required (VERSION 3.11)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v3.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------
# Usage with CMake

# If using CMake, it is recommended to link against the project-provided benchmark::benchmark and benchmark::benchmark_main targets using target_link_libraries. It is possible to use find_package to import an installed version of the library.
# find_package(benchmark REQUIRED)
# Alternatively, add_subdirectory will incorporate the library directly in to one's CMake project.
# add_subdirectory(benchmark)
# Either way, link to the library as follows.
# target_link_libraries(MyTarget benchmark::benchmark)

project(ftxui-starter
  LANGUAGES CXX
  VERSION 1.0.0
)

# add_executable(ftxui-starter src/main.cpp)
add_executable(ftxui-starter src/example.cpp)
target_include_directories(ftxui-starter PRIVATE src)

target_link_libraries(ftxui-starter
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component # Not needed for this example.
)

if (EMSCRIPTEN)
  string(APPEND CMAKE_CXX_FLAGS " -s USE_PTHREADS")
  string(APPEND CMAKE_EXE_LINKER_FLAGS " -s ASYNCIFY")
  string(APPEND CMAKE_EXE_LINKER_FLAGS " -s PROXY_TO_PTHREAD")

  foreach(file "index.html" "run_webassembly.py")
    configure_file("src/${file}" ${file})
  endforeach(file)
endif()
