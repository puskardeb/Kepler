cmake_minimum_required(VERSION "3.19.2")

project("Kepler")

add_executable("$(PROJECT_NAME)" );

install(TARGETS "$(PROJECT_NAME)" DESTINATION build)
install(FILES "Sandbox.cpp" DESTINATION src);