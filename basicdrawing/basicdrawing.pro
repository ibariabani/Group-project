QT += widgets

HEADERS       = renderarea.h \
                window.h
SOURCES       = main.cpp \
                renderarea.cpp \
                window.cpp
RESOURCES     =

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/painting/basicdrawing
INSTALLS += target 
