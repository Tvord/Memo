cmake_minimum_required(VERSION 3.0.0)
project(Memo VERSION 0.1.0)

include_directories(DataCards/include)
include_directories(Database)

add_library(memback STATIC backend.h DataCards/include/iDataCard.h DataCards/src/iDataCard.cpp
        DataCards/src/Note.cpp DataCards/include/Note.h DataCards/src/Reminder.cpp DataCards/include/Reminder.h
        DataCards/src/Repeater.cpp DataCards/include/Repeater.h Database/dbconnect.cpp Database/dbconnect.h Database/queries.h)
target_link_libraries(memback sqlite3)

# Tests zone
enable_testing()
link_directories(/usr/local/lib/)
#set(EXECUTABLE_OUTPUT_PATH /home/engin/gtest/testing)
add_executable(tests_backend tests/TestsDatabase.cpp)
target_link_libraries(tests_backend memback gtest gtest_main pthread)

include(GoogleTest)
gtest_discover_tests(tests_backend)
