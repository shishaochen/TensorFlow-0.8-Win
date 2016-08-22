# Install script for directory: D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/libjpeg")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Library")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/build/jpeg.lib")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Header")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/jerror.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Header")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/jmorecfg.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Header")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/jpeglib.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Header")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/build/jconfig.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libjpeg/doc" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/README")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libjpeg/doc" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/install.txt")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libjpeg/doc" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/usage.txt")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libjpeg/doc" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/wizard.txt")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libjpeg/doc" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/example.c")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libjpeg/doc" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/libjpeg.txt")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libjpeg/doc" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/structure.txt")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libjpeg/doc" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/coderules.txt")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libjpeg/doc" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/filelist.txt")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libjpeg/doc" TYPE FILE FILES "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/change.log")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "D:/cmakeTF/tensorflow0.8/third_party/jpeg-9a/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
