# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux
TARGET = VisualKitStream
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += GUI/Calibration/SingleCameraCalibration.cpp.cc GUI/CalibrationExecutor.cpp.cc GUI/Cameras/CameraViewer.cpp.cc GUI/Cameras/ImageViewer.cpp.cc GUI/FieldOfViewWindow.cpp.cc GUI/MainMenuWindow.cpp.cc NetWork/CommunicatingSocket.cpp NetWork/Socket.cpp NetWork/SocketException.cpp NetWork/TCPServerSocket.cpp NetWork/TCPSocket.cpp NetWork/UDPSocket.cpp Utils/Calibration/CameraCalibration.cpp Utils/Calibration/PointsCollectorChess.cpp Utils/Calibration/PointsCollectorCircles.cpp Utils/Calibration/utils.cpp Utils/FieldOfViewChecker.cpp Utils/ImageProcessing/ImageTransformation.cpp Utils/ImagesColor/FalseColor.cpp main.cpp
HEADERS += GUI/Calibration/SingleCameraCalibration.h GUI/CalibrationExecutor.h GUI/Cameras/CameraViewer.h GUI/Cameras/ImageViewer.h GUI/FieldOfViewWindow.h GUI/MainMenuWindow.h NetWork/CommunicatingSocket.h NetWork/FillAddress.h NetWork/Socket.h NetWork/SocketException.h NetWork/TCPServerSocket.h NetWork/TCPSocket.h NetWork/UDPSocket.h Utils/Calibration/CameraCalibration.h Utils/Calibration/PointsCollectorBase.h Utils/Calibration/PointsCollectorChess.h Utils/Calibration/PointsCollectorCircles.h Utils/Calibration/utils.h Utils/FieldOfViewChecker.h Utils/ImageProcessing/ImageTransformation.h Utils/ImagesColor/FalseColor.h Utils/ImagesColor/LutTables.h
FORMS += GUI/Calibration/SingleCameraCalibration.ui GUI/CalibrationExecutor.ui GUI/Cameras/CameraViewer.ui GUI/Cameras/ImageViewer.ui GUI/FieldOfViewWindow.ui GUI/MainMenuWindow.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
