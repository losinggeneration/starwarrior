set(STARWARRIOR_INC ${CMAKE_SOURCE_DIR}/include)
include_directories(
	${STARWARRIOR_INC}
	${STARWARRIOR_INC}/components
	${STARWARRIOR_INC}/spatials
	${STARWARRIOR_INC}/systems
)

add_subdirectory(components)
add_subdirectory(spatials)
add_subdirectory(systems)

add_executable(starwarrior
	EntityFactory.cpp
	StarWarrior.cpp
)

target_link_libraries(starwarrior components spatials systems)