# CMakeList.txt : CMake project for Assignment 1; Dead Man's Draw++, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeTarget 
   "DeadMansDraw.cpp" 
   "DeadMansDraw.h"  
   "Deck.cpp" 
   "Deck.h" 
   "DiscardPile.cpp" 
   "DiscardPile.h" 
   "Player.cpp" 
   "Player.h" 
   "Bank.cpp" 
   "Bank.h" 
   "PlayArea.cpp" 
   "PlayArea.h" 
    
   "GameCards/CardTypes.h"
   "GameCards/Card.cpp"
   "GameCards/Card.h"
   "GameCards/Anchor.cpp"
   "GameCards/Chest.cpp"
   "GameCards/Hook.cpp"
   "GameCards/Map.cpp"
   "GameCards/Sword.cpp"
   "GameCards/Cannon.cpp"
   "GameCards/Oracle.cpp"
   "GameCards/Key.cpp"
   "GameCards/Mermaid.cpp"
   "GameCards/Kraken.cpp"

)

if (CMAKE_VERSION VERSION_GREATER 3.12)
 set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
