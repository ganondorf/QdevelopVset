QT = gui core
CONFIG += qt debug warn_on console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/animatorwindow.ui
HEADERS = src/mainwindowimpl.h \
 src/animatorwindow.h \
 src/Experiment.h \
 src/ShotPoint.h \
 src/pugiconfig.hpp \
 src/pugixml.hpp \
 src/Model.h \
 src/ExperimentManager.h \
 src/Workspace.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/animatorwindow.cpp \
 src/Experiment.cpp \
 src/ShotPoint.cpp \
 src/pugixml.cpp \
 src/Model.cpp \
 src/TimeModel.cpp \
 src/VelocityModel.cpp \
 src/PerturbationModel.cpp \
 src/CoverageModel.cpp \
 src/ExperimentManager.cpp \
 src/Workspace.cpp
TEMPLATE = app
LIBS =
