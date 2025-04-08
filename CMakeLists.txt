# CMakeList.txt : CMake project for Assignment 1; Dead Man's Draw++, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeTarget "DeadMansDraw.cpp" "DeadMansDraw.h"  "Deck.h" "DiscardPile.h" "Player.h" "Bank.h" "PlayArea.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
