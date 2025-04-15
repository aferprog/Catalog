target_sources(
	CatalogServer PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/CSVCoinStorage.h ${CMAKE_CURRENT_SOURCE_DIR}/CSVCoinStorage.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CSVUserStorage.h ${CMAKE_CURRENT_SOURCE_DIR}/CSVUserStorage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/FileCoinStorage.h ${CMAKE_CURRENT_SOURCE_DIR}/FileCoinStorage.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/FileUserStorage.h ${CMAKE_CURRENT_SOURCE_DIR}/FileUserStorage.cpp
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(CatalogServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})