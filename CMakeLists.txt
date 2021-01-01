cmake_minimum_required(VERSION 3.17)
project(SK2ProjectKahoot)

set(CMAKE_CXX_STANDARD 17)

add_executable(SK2ProjectKahoot main.cpp Kahoot.hpp Question.hpp cmake-build-debug/Answer.cpp ABCnetInterface.hpp Answer.hpp ABCuserInterface.hpp ABCq&aInterface.hpp QnAManager.hpp)