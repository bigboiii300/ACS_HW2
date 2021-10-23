cmake_minimum_required(VERSION 3.20)
project(ACS_HW_2_Igor)

set(CMAKE_CXX_STANDARD 17)

add_executable(ACS_HW_2_Igor main.cpp ReplaceWithSymbols.cpp ReplaceWithSymbols.h ReplaceWithDigit.cpp ReplaceWithDigit.h ReplaceByShift.cpp ReplaceByShift.h EncryptionText.cpp EncryptionText.h container.cpp container.h utils.h)
