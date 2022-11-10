## >>>>>>>>>>>>>>>
## >>>>>>>>>>>>>>>
add_library(iri iri.cpp "funciones.h" "funciones.cpp")
## <<<<<<<<<<<<<<<
## <<<<<<<<<<<<<<<

target_include_directories(iri PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
