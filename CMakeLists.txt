cmake_minimum_required(VERSION 3.14)
project(ArtemisUtility)
add_library(${PROJECT_NAME} STATIC
    "Conversion.cpp"
    "DataStructures.cpp"
    "String.cpp"
)
