cmake_minimum_required(VERSION 3.20)
project(WarpBootstrapCompiler)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(MAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

add_compile_options(
		-fconstexpr-ops-limit=3355443299 
		-fconstexpr-depth=1280
		-fconcepts-diagnostics-depth=2 
		-ftemplate-depth=10000
		-frounding-math
		-fmodules-ts
	)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_SOURCE_DIR}/Include)
# Third party includes
include_directories(${CMAKE_SOURCE_DIR}/Include/ThirdParty/constexpr-random/include)
include_directories(${CMAKE_SOURCE_DIR}/Include/ThirdParty/Sprout)

FILE(GLOB_RECURSE SourceFiles ${CMAKE_SOURCE_DIR}/Source/*.cpp)
FILE(GLOB_RECURSE TestSourceFiles ${CMAKE_SOURCE_DIR}/Test/*.cpp)

add_library(libwarp STATIC) 
target_sources(libwarp PUBLIC ${SourceFiles}) 
target_link_libraries(libwarp ${CONAN_LIBS})
target_precompile_headers(libwarp PUBLIC ${HeaderFiles})

add_executable(test ${TestSourceFiles})
target_sources(test PUBLIC ${TestSourceFiles})
target_link_libraries(test libwarp ${CONAN_LIBS})

