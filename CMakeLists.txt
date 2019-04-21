cmake_minimum_required(VERSION 3.5 )

### c++11 standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project( Final )

include_directories( include )

add_executable( dna1 apps/analyzeDNA1.cpp )
add_executable( dna2 apps/analyzeDNA2.cpp )
add_executable( ecg apps/analyzeECG.cpp )
add_executable( area apps/area.cpp )
add_executable( calc apps/calculator.cpp )
add_executable( comp_dna apps/complementaryDNA.cpp )
add_executable( euclidean apps/euclidean.cpp )
add_executable( heron apps/heron.cpp )
add_executable( basic apps/main1.cpp )
add_executable( memory apps/main2.cpp )
add_executable( heap apps/test_heap.cpp )
add_executable( point apps/testPoint.cpp )
add_executable( trans_dna apps/translateDNA.cpp )
add_executable( tree apps/test_tree.cpp )
add_executable( uniquewords apps/unique_words.cpp )
add_executable( countdna apps/countDNA.cpp )
add_executable( countwords apps/count_words.cpp )

