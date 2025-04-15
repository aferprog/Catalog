# CMakeList.txt : CMake project for TempCMake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
project ("Catalog")


# Add source to this project's executable.
add_executable (CatalogServer "main.cpp")

target_sources(
	CatalogServer PRIVATE 
	csv.hpp
)

add_subdirectory("../General" "${CMAKE_BINARY_DIR}/General")
add_subdirectory(Servers)
add_subdirectory(Controllers)
add_subdirectory(Storages)
add_subdirectory(Objects)

target_include_directories(CatalogServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(CatalogServer PRIVATE GeneralLib)
find_package(rpclib CONFIG REQUIRED)
target_link_libraries(CatalogServer PRIVATE rpclib::rpc)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CatalogServer PROPERTY CXX_STANDARD 20)
endif()


# TODO: Add tests and install targets if needed.
