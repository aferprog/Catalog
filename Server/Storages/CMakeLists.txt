target_sources(
	CatalogServer PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/IUserStorage.h
	${CMAKE_CURRENT_SOURCE_DIR}/ICoinStorage.h
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/FileStorages)
target_include_directories(CatalogServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})