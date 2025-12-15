cmake_minimum_required(VERSION 3.10)
project(Laboratory_3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции только для GCC/Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")
endif()

# Установка Google Test
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
    TLS_VERIFY false
)

# Отключаем использование статической библиотеки и переключаем на динамическую
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Все исходные файлы для основной библиотеки
set(LAB3_SOURCES
    src/FigureArray.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Octagon.cpp
)

# Основная библиотека проекта
add_library(${PROJECT_NAME}_lib ${LAB3_SOURCES})
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Основной исполняемый файл
add_executable(${PROJECT_NAME}_exe main.cpp)
target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME}_lib)
target_include_directories(${PROJECT_NAME}_exe PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Тесты
enable_testing()

# Список тестовых файлов
set(TEST_SOURCES
    test/test_array.cpp
    test/test_octagon.cpp
    test/test_square.cpp
    test/test_triangle.cpp
)

# Тестовый исполняемый файл
add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${PROJECT_NAME}_lib gtest_main)
target_include_directories(${PROJECT_NAME}_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Регистрация тестов
add_test(NAME ${PROJECT_NAME}_tests COMMAND ${PROJECT_NAME}_tests)