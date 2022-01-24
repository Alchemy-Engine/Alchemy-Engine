SET(Launcher)

IF(WIN32)
    ADD_SUBDIRECTORY(Windows)
ENDIF(WIN32)

ADD_LIBRARY(Launcher STATIC 
    Launcher.cc
)

TARGET_LINK_LIBRARIES( Alchemy PRIVATE 
    Launcher
)

