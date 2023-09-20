cmake_minimum_required(VERSION 3.14)
project(lanelet2_extension_python)

find_package(mrt_cmake_modules REQUIRED)
# NOTE: defined in mrt_cmake_modules/FindBoostPython.cmake
find_package(BoostPython REQUIRED)

include_directories(
  ${BoostPython_INCLUDE_DIRS}
)

include(UseMrtStdCompilerFlags)
include(GatherDeps)
find_package(AutoDeps REQUIRED COMPONENTS ${DEPENDEND_PACKAGES})
mrt_parse_package_xml()
mrt_python_module_setup()
mrt_glob_files(PROJECT_PYTHON_SOURCE_FILES_SRC "src/*.cpp")
if (PROJECT_PYTHON_SOURCE_FILES_SRC)
  mrt_add_python_api(lanelet2_extension
    FILES ${PROJECT_PYTHON_SOURCE_FILES_SRC}
  )
endif()

mrt_install(FILES ${PROJECT_INSTALL_FILES})
