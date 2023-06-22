project(main)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

ADD_SUBDIRECTORY(SFML)
ADD_SUBDIRECTORY(googletest)
ADD_EXECUTABLE(main main.cpp Chessboard.cpp Piece.cpp Knight.cpp Bishop.cpp Pawn.cpp Queen.cpp King.cpp Rook.cpp Input.cpp GameManager.cpp BlackTeam.cpp WhiteTeam.cpp)
ADD_EXECUTABLE(test Unit_Test.cpp)
# ADD_EXECUTABLE(BlackTeamTesting BlackTeamTesting.cpp WhiteTeam.cpp BlackTeam.cpp Pawn.cpp Bishop.cpp Knight.cpp Piece.cpp)
# ADD_EXECUTABLE(TextBasedChess textBasedChess.cpp WhiteTeam.cpp BlackTeam.cpp Piece.cpp Pawn.cpp Bishop.cpp Rook.cpp Knight.cpp King.cpp Queen.cpp GameManager.cpp Input.cpp)

TARGET_LINK_LIBRARIES(main sfml-graphics sfml-window sfml-system)
TARGET_LINK_LIBRARIES(test gtest)
# TARGET_LINK_LIBRARIES(TextBasedChess sfml-graphics sfml-window sfml-system)
