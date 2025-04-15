target_sources(
	CatalogServer PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/User.h ${CMAKE_CURRENT_SOURCE_DIR}/User.cpp
)
target_include_directories(CatalogServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})