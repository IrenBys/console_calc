cmake_minimum_required(VERSION 3.15)

project(console_calc)

include_directories(${PROJECT_SOURCE_DIR}/include)

include(FetchContent)

# Подключаем mathlib через FetchContent
FetchContent_Declare(
    mathlib
    GIT_REPOSITORY https://github.com/IrenBys/mathlib.git
    GIT_TAG main # или конкретный коммит
)
FetchContent_MakeAvailable(mathlib)

add_executable(console_calc
    src/main.cpp
    src/runner.cpp
    src/parser.cpp
    src/checker.cpp
    src/calculator.cpp
    src/printer.cpp
)

# --- Линкуем mathlib к проекту ---
target_link_libraries(console_calc PRIVATE mathlib)

# --- clang-format target ---
find_program(CLANG_FORMAT NAMES clang-format)

if(CLANG_FORMAT)
    file(GLOB_RECURSE ALL_CXX_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*.h
    )

    add_custom_target(
        clang_format
        COMMAND ${CLANG_FORMAT}
        -i
        ${ALL_CXX_SOURCE_FILES}
        COMMENT "Running clang-format on all source files"
    )
endif()

# --- clang-tidy ---
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")

# Установка в локальную папку проекта
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install" CACHE PATH "Install path" FORCE)
install(TARGETS console_calc DESTINATION bin)