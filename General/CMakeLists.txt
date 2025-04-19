add_library(
	GeneralLib 
	${CMAKE_CURRENT_SOURCE_DIR}/CoreCoin.h ${CMAKE_CURRENT_SOURCE_DIR}/CoreCoin.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CoreCollection.h
	${CMAKE_CURRENT_SOURCE_DIR}/IController.h
)

find_package(rpclib CONFIG REQUIRED)
target_link_libraries(GeneralLib PUBLIC rpclib::rpc)