set(STARWARRIOR_INC ${CMAKE_SOURCE_DIR}/include)
include_directories(
	${SDL_INCLUDE_DIR}
	${SDLGFX_INCLUDE_DIR}
	${SDLTTF_INCLUDE_DIR}
	${HECATE_INCLUDE_DIR}
	${STARWARRIOR_INC}
	${STARWARRIOR_INC}/components
	${STARWARRIOR_INC}/spatials
	${STARWARRIOR_INC}/systems
)

add_subdirectory(components)
add_subdirectory(spatials)
add_subdirectory(systems)
add_subdirectory(utils)

add_executable(starwarrior
	EntityFactory.cpp
	StarWarrior.cpp
)

target_link_libraries(starwarrior systems components spatials utils ${SDL_LIBRARY} ${SDLGFX_LIBRARY} ${SDLTTF_LIBRARY} ${HECATE_LIBRARY})
