#CMakeLists du répertoire ocean

add_library(ocean
	SHARED
	camera.cxx
	window.cxx )
	
install (TARGETS ocean
	DESTINATION lib)
	
file(
	GLOB
	headers
	*.hxx
)

install(FILES ${headers}
	DESTINATION include/${CMAKE_PROJECT_NAME})
