# CMakeList.txt : CMake project for OOP_Games, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (OOP_Games  "X_O_App.cpp"  "X_O_Board.cpp" "RandomPlayer.cpp" "Player.cpp" "GameManager.cpp" "X_O_5x5_Board.cpp" "X_O_5x5_BoardData.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OOP_Games PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
