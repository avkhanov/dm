set (SOURCE _WindowTemplate.cpp)

if (WIN32)
    set (SOURCE ${SOURCE} WIN32Window.cpp)
endif (WIN32)

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set (SOURCE ${SOURCE} LinuxWindow.cpp)
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")

add_library (window ${SOURCE})

