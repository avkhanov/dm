set (SOURCE _WindowTemplate.cpp)

if (WIN32)
    set (SOURCE ${SOURCE} WIN32Window.cpp)
endif (WIN32)

add_library (window ${SOURCE})

