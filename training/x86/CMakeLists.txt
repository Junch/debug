CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

PROJECT (Example)

IF(WIN32)
    # make the Release version create a PDB
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    # minimize the size or the resulting EXE
    SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
ENDIF()

SET(SRC_LIST example.cpp)
ADD_EXECUTABLE(example ${SRC_LIST})
