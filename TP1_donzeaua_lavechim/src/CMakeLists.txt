#CMakeLists du répertoire src

add_library(src
	SHARED
	Dvector.cpp
	Height.cpp
	WaveModel.cpp
	GerstnerWave.cpp 
	GerstnerWaveModel.cpp
	)
	
install (TARGETS src
	DESTINATION lib)
	
file(
	GLOB
	headers
	*.h
)

install(FILES ${headers}
	DESTINATION include/${CMAKE_PROJECT_NAME})
