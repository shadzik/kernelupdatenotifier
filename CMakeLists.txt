PROJECT( kernelupdatenotifier)
FIND_PACKAGE(KDE4 REQUIRED)
INCLUDE_DIRECTORIES( ${KDE4_INCLUDES} )

SET(KDE4ProjectSources main.cpp kernelupdatenotifier.cpp)

KDE4_ADD_EXECUTABLE(kernelupdatenotifier ${KDE4ProjectSources} )

TARGET_LINK_LIBRARIES(kernelupdatenotifier ${KDE4_KDEUI_LIBS} kworkspace)

install(TARGETS kernelupdatenotifier DESTINATION ${INSTALL_TARGETS_DEFAULT_ARGS})
