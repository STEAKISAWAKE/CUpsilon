cmake_minimum_required(VERSION 3.10)
project(Upsilon C)

# Build libraries first
add_subdirectory(Libraries)

# Build Upsilon
add_subdirectory(Source)