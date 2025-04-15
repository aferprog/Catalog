target_sources(
	CatalogServer PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/Controller.h ${CMAKE_CURRENT_SOURCE_DIR}/Controller.cpp
)
target_include_directories(CatalogServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})