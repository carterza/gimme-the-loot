cmake_minimum_required(VERSION 2.8)
 
project(gimme-the-loot)

#---------------------------------------------------------------
set(ACTOR_H
	./Actor.hpp
	./Ai.hpp
	./Attacker.hpp
	./Container.hpp
	./Destructible.hpp
	./MonsterAi.hpp
	./MonsterDestructible.hpp
	./PlayerAi.hpp
	./PlayerDestructible.hpp
)
SOURCE_GROUP("Header Files\\Actor" FILES ${ACTOR_H})
set(ACTOR_S
	./Actor.cpp
	./Ai.cpp
	./Attacker.cpp
	./Container.cpp
	./Destructible.cpp
	./MonsterAi.cpp
	./MonsterDestructible.cpp
	./PlayerAi.cpp
	./PlayerDestructible.cpp
)
SOURCE_GROUP("Source Files\\Actor" FILES ${ACTOR_S})
#---------------------------------------------------------------
set(MAP_H
	./Map.hpp
)
SOURCE_GROUP("Header Files\\Map" FILES ${MAP_H})
set(MAP_S
	./Map.cpp
)
SOURCE_GROUP("Source Files\\Map" FILES ${MAP_S})
#---------------------------------------------------------------
set(PICKABLE_H
	./Confuser.hpp
	./Fireball.hpp
	./Healer.hpp
	./LightningBolt.hpp
	./Pickable.hpp
)
SOURCE_GROUP("Header Files\\Pickable" FILES ${PICKABLE_H})
set(PICKABLE_S
	./Confuser.cpp
	./Fireball.cpp
	./Healer.cpp
	./LightningBolt.cpp
	./Pickable.cpp
)
SOURCE_GROUP("Source Files\\Pickable" FILES ${PICKABLE_S})
#---------------------------------------------------------------
set(ENGINE_H
  ./Engine.hpp
  ./Gui.hpp
  ./Menu.hpp
  ./gmtl.pb.h
)
SOURCE_GROUP("Header Files\\Engine" FILES ${ENGINE_H})
set(ENGINE_S
  ./Engine.cpp
  ./Gui.cpp
  ./Menu.cpp
  ./gmtl.pb.cc
)
SOURCE_GROUP("Source Files\\Engine" FILES ${ENGINE_S})
#---------------------------------------------------------------
set (HDRS
	${ACTOR_H}
	${MAP_H}
	${PICKABLE_H}
	${ENGINE_H}
)

set (SRCS
	${ACTOR_S}
	${MAP_S}
	${PICKABLE_S}
	${ENGINE_S}
	main.cpp
)

find_package (Libtcod REQUIRED)
include_directories (${LIBTCOD_INCLUDE_DIRS})

find_package (Libtcodxx REQUIRED)
include_directories (${LIBTCODXX_INCLUDE_DIRS})

find_package (Libprotobuf REQUIRED)

add_executable (gimme-the-loot ${HDRS} ${SRCS})
set_target_properties(gimme-the-loot PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries (gimme-the-loot
  ${LIBTCOD_LIBRARIES}
  ${LIBTCODXX_LIBRARIES}
  ${PROTOBUF_LIBRARIES}
)

ADD_CUSTOM_COMMAND(
  TARGET gimme-the-loot
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_SOURCE_DIR}/gmtl.png ${EXECUTABLE_OUTPUT_PATH}
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_SOURCE_DIR}/terminal.png ${EXECUTABLE_OUTPUT_PATH}
)