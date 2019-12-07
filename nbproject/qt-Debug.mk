#############################################################################
# Makefile for building: dist/Debug/GNU-Linux/VisualKitStream
# Generated by qmake (2.01a) (Qt 4.8.7) on: ?? ??? 7 10:57:41 2019
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -std=c++14 -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -Inbproject -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I/usr/local/opencv_3.4.7/include -I. -I. -Inbproject -I.
LINK          = g++
LFLAGS        = -m64
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_aruco.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_bgsegm.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_bioinspired.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_calib3d.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_ccalib.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_core.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_datasets.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_dnn.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_dnn_objdetect.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_dpm.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_face.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_features2d.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_flann.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_fuzzy.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_hfs.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_highgui.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_img_hash.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_imgcodecs.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_imgproc.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_line_descriptor.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_ml.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_objdetect.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_optflow.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_phase_unwrapping.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_photo.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_plot.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_reg.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_rgbd.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_saliency.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_sfm.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_shape.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_stereo.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_stitching.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_structured_light.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_superres.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_surface_matching.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_text.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_tracking.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_video.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_videoio.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_videostab.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_xfeatures2d.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_ximgproc.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_xobjdetect.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib /usr/local/opencv_3.4.7/lib/libopencv_xphoto.so -Wl,-rpath,/usr/local/opencv_3.4.7/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/Debug/GNU-Linux/

####### Files

SOURCES       = GUI/CalibrationExecutor.cpp.cc \
		GUI/Cameras/CameraViewer.cpp.cc \
		GUI/Cameras/ImageViewer.cpp.cc \
		GUI/MainMenuWindow.cpp.cc \
		NetWork/CommunicatingSocket.cpp \
		NetWork/Socket.cpp \
		NetWork/SocketException.cpp \
		NetWork/TCPServerSocket.cpp \
		NetWork/TCPSocket.cpp \
		NetWork/UDPSocket.cpp \
		Utils/Calibration/CameraCalibration.cpp \
		Utils/Calibration/PointsCollectorChess.cpp \
		Utils/Calibration/PointsCollectorCircles.cpp \
		Utils/Calibration/utils.cpp \
		Utils/FieldOfViewChecker.cpp \
		Utils/ImageProcessing/ImageTransformation.cpp \
		Utils/ImagesColor/FalseColor.cpp \
		main.cpp moc_CalibrationExecutor.cpp \
		moc_CameraViewer.cpp \
		moc_ImageViewer.cpp \
		moc_MainMenuWindow.cpp \
		moc_CameraCalibration.cpp
OBJECTS       = build/Debug/GNU-Linux/CalibrationExecutor.cpp.o \
		build/Debug/GNU-Linux/CameraViewer.cpp.o \
		build/Debug/GNU-Linux/ImageViewer.cpp.o \
		build/Debug/GNU-Linux/MainMenuWindow.cpp.o \
		build/Debug/GNU-Linux/CommunicatingSocket.o \
		build/Debug/GNU-Linux/Socket.o \
		build/Debug/GNU-Linux/SocketException.o \
		build/Debug/GNU-Linux/TCPServerSocket.o \
		build/Debug/GNU-Linux/TCPSocket.o \
		build/Debug/GNU-Linux/UDPSocket.o \
		build/Debug/GNU-Linux/CameraCalibration.o \
		build/Debug/GNU-Linux/PointsCollectorChess.o \
		build/Debug/GNU-Linux/PointsCollectorCircles.o \
		build/Debug/GNU-Linux/utils.o \
		build/Debug/GNU-Linux/FieldOfViewChecker.o \
		build/Debug/GNU-Linux/ImageTransformation.o \
		build/Debug/GNU-Linux/FalseColor.o \
		build/Debug/GNU-Linux/main.o \
		build/Debug/GNU-Linux/moc_CalibrationExecutor.o \
		build/Debug/GNU-Linux/moc_CameraViewer.o \
		build/Debug/GNU-Linux/moc_ImageViewer.o \
		build/Debug/GNU-Linux/moc_MainMenuWindow.o \
		build/Debug/GNU-Linux/moc_CameraCalibration.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		nbproject/qt-Debug.pro
QMAKE_TARGET  = VisualKitStream
DESTDIR       = dist/Debug/GNU-Linux/
TARGET        = dist/Debug/GNU-Linux/VisualKitStream

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: qttmp-Debug.mk $(TARGET)

$(TARGET): ui_CalibrationExecutor.h ui_CameraViewer.h ui_ImageViewer.h ui_MainMenuWindow.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) dist/Debug/GNU-Linux/ || $(MKDIR) dist/Debug/GNU-Linux/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9][^0-9]*\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

qttmp-Debug.mk: nbproject/qt-Debug.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro

dist: 
	@$(CHK_DIR_EXISTS) build/Debug/GNU-Linux/VisualKitStream1.0.0 || $(MKDIR) build/Debug/GNU-Linux/VisualKitStream1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/Debug/GNU-Linux/VisualKitStream1.0.0/ && $(COPY_FILE) --parents GUI/CalibrationExecutor.h GUI/Cameras/CameraViewer.h GUI/Cameras/ImageViewer.h GUI/MainMenuWindow.h NetWork/CommunicatingSocket.h NetWork/FillAddress.h NetWork/Socket.h NetWork/SocketException.h NetWork/TCPServerSocket.h NetWork/TCPSocket.h NetWork/UDPSocket.h Utils/Calibration/CameraCalibration.h Utils/Calibration/PointsCollectorBase.h Utils/Calibration/PointsCollectorChess.h Utils/Calibration/PointsCollectorCircles.h Utils/Calibration/utils.h Utils/FieldOfViewChecker.h Utils/ImageProcessing/ImageTransformation.h Utils/ImagesColor/FalseColor.h Utils/ImagesColor/LutTables.h build/Debug/GNU-Linux/VisualKitStream1.0.0/ && $(COPY_FILE) --parents GUI/CalibrationExecutor.cpp.cc GUI/Cameras/CameraViewer.cpp.cc GUI/Cameras/ImageViewer.cpp.cc GUI/MainMenuWindow.cpp.cc NetWork/CommunicatingSocket.cpp NetWork/Socket.cpp NetWork/SocketException.cpp NetWork/TCPServerSocket.cpp NetWork/TCPSocket.cpp NetWork/UDPSocket.cpp Utils/Calibration/CameraCalibration.cpp Utils/Calibration/PointsCollectorChess.cpp Utils/Calibration/PointsCollectorCircles.cpp Utils/Calibration/utils.cpp Utils/FieldOfViewChecker.cpp Utils/ImageProcessing/ImageTransformation.cpp Utils/ImagesColor/FalseColor.cpp main.cpp build/Debug/GNU-Linux/VisualKitStream1.0.0/ && $(COPY_FILE) --parents GUI/CalibrationExecutor.ui GUI/Cameras/CameraViewer.ui GUI/Cameras/ImageViewer.ui GUI/MainMenuWindow.ui build/Debug/GNU-Linux/VisualKitStream1.0.0/ && (cd `dirname build/Debug/GNU-Linux/VisualKitStream1.0.0` && $(TAR) VisualKitStream1.0.0.tar VisualKitStream1.0.0 && $(COMPRESS) VisualKitStream1.0.0.tar) && $(MOVE) `dirname build/Debug/GNU-Linux/VisualKitStream1.0.0`/VisualKitStream1.0.0.tar.gz . && $(DEL_FILE) -r build/Debug/GNU-Linux/VisualKitStream1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Debug.mk


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_CalibrationExecutor.cpp moc_CameraViewer.cpp moc_ImageViewer.cpp moc_MainMenuWindow.cpp moc_CameraCalibration.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_CalibrationExecutor.cpp moc_CameraViewer.cpp moc_ImageViewer.cpp moc_MainMenuWindow.cpp moc_CameraCalibration.cpp
moc_CalibrationExecutor.cpp: ui_CalibrationExecutor.h \
		GUI/Cameras/CameraViewer.h \
		ui_CameraViewer.h \
		GUI/Cameras/ImageViewer.h \
		ui_ImageViewer.h \
		GUI/CalibrationExecutor.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) GUI/CalibrationExecutor.h -o moc_CalibrationExecutor.cpp

moc_CameraViewer.cpp: ui_CameraViewer.h \
		GUI/Cameras/CameraViewer.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) GUI/Cameras/CameraViewer.h -o moc_CameraViewer.cpp

moc_ImageViewer.cpp: ui_ImageViewer.h \
		GUI/Cameras/ImageViewer.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) GUI/Cameras/ImageViewer.h -o moc_ImageViewer.cpp

moc_MainMenuWindow.cpp: ui_MainMenuWindow.h \
		GUI/CalibrationExecutor.h \
		ui_CalibrationExecutor.h \
		GUI/Cameras/CameraViewer.h \
		ui_CameraViewer.h \
		GUI/Cameras/ImageViewer.h \
		ui_ImageViewer.h \
		GUI/MainMenuWindow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) GUI/MainMenuWindow.h -o moc_MainMenuWindow.cpp

moc_CameraCalibration.cpp: Utils/Calibration/CameraCalibration.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) Utils/Calibration/CameraCalibration.h -o moc_CameraCalibration.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_CalibrationExecutor.h ui_CameraViewer.h ui_ImageViewer.h ui_MainMenuWindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_CalibrationExecutor.h ui_CameraViewer.h ui_ImageViewer.h ui_MainMenuWindow.h
ui_CalibrationExecutor.h: GUI/CalibrationExecutor.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic GUI/CalibrationExecutor.ui -o ui_CalibrationExecutor.h

ui_CameraViewer.h: GUI/Cameras/CameraViewer.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic GUI/Cameras/CameraViewer.ui -o ui_CameraViewer.h

ui_ImageViewer.h: GUI/Cameras/ImageViewer.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic GUI/Cameras/ImageViewer.ui -o ui_ImageViewer.h

ui_MainMenuWindow.h: GUI/MainMenuWindow.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic GUI/MainMenuWindow.ui -o ui_MainMenuWindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/Debug/GNU-Linux/CalibrationExecutor.cpp.o: GUI/CalibrationExecutor.cpp.cc GUI/CalibrationExecutor.h \
		ui_CalibrationExecutor.h \
		GUI/Cameras/CameraViewer.h \
		ui_CameraViewer.h \
		GUI/Cameras/ImageViewer.h \
		ui_ImageViewer.h \
		ui_MainMenuWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/CalibrationExecutor.cpp.o GUI/CalibrationExecutor.cpp.cc

build/Debug/GNU-Linux/CameraViewer.cpp.o: GUI/Cameras/CameraViewer.cpp.cc GUI/Cameras/CameraViewer.h \
		ui_CameraViewer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/CameraViewer.cpp.o GUI/Cameras/CameraViewer.cpp.cc

build/Debug/GNU-Linux/ImageViewer.cpp.o: GUI/Cameras/ImageViewer.cpp.cc GUI/Cameras/ImageViewer.h \
		ui_ImageViewer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/ImageViewer.cpp.o GUI/Cameras/ImageViewer.cpp.cc

build/Debug/GNU-Linux/MainMenuWindow.cpp.o: GUI/MainMenuWindow.cpp.cc GUI/MainMenuWindow.h \
		ui_MainMenuWindow.h \
		GUI/CalibrationExecutor.h \
		ui_CalibrationExecutor.h \
		GUI/Cameras/CameraViewer.h \
		ui_CameraViewer.h \
		GUI/Cameras/ImageViewer.h \
		ui_ImageViewer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/MainMenuWindow.cpp.o GUI/MainMenuWindow.cpp.cc

build/Debug/GNU-Linux/CommunicatingSocket.o: NetWork/CommunicatingSocket.cpp NetWork/CommunicatingSocket.h \
		NetWork/Socket.h \
		NetWork/SocketException.h \
		NetWork/FillAddress.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/CommunicatingSocket.o NetWork/CommunicatingSocket.cpp

build/Debug/GNU-Linux/Socket.o: NetWork/Socket.cpp NetWork/Socket.h \
		NetWork/SocketException.h \
		NetWork/FillAddress.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/Socket.o NetWork/Socket.cpp

build/Debug/GNU-Linux/SocketException.o: NetWork/SocketException.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/SocketException.o NetWork/SocketException.cpp

build/Debug/GNU-Linux/TCPServerSocket.o: NetWork/TCPServerSocket.cpp NetWork/TCPServerSocket.h \
		NetWork/Socket.h \
		NetWork/SocketException.h \
		NetWork/TCPSocket.h \
		NetWork/CommunicatingSocket.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/TCPServerSocket.o NetWork/TCPServerSocket.cpp

build/Debug/GNU-Linux/TCPSocket.o: NetWork/TCPSocket.cpp NetWork/TCPSocket.h \
		NetWork/CommunicatingSocket.h \
		NetWork/Socket.h \
		NetWork/SocketException.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/TCPSocket.o NetWork/TCPSocket.cpp

build/Debug/GNU-Linux/UDPSocket.o: NetWork/UDPSocket.cpp NetWork/UDPSocket.h \
		NetWork/CommunicatingSocket.h \
		NetWork/Socket.h \
		NetWork/SocketException.h \
		NetWork/FillAddress.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/UDPSocket.o NetWork/UDPSocket.cpp

build/Debug/GNU-Linux/CameraCalibration.o: Utils/Calibration/CameraCalibration.cpp Utils/Calibration/CameraCalibration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/CameraCalibration.o Utils/Calibration/CameraCalibration.cpp

build/Debug/GNU-Linux/PointsCollectorChess.o: Utils/Calibration/PointsCollectorChess.cpp Utils/Calibration/PointsCollectorChess.h \
		Utils/Calibration/PointsCollectorBase.h \
		Utils/Calibration/utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/PointsCollectorChess.o Utils/Calibration/PointsCollectorChess.cpp

build/Debug/GNU-Linux/PointsCollectorCircles.o: Utils/Calibration/PointsCollectorCircles.cpp Utils/Calibration/PointsCollectorCircles.h \
		Utils/Calibration/PointsCollectorBase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/PointsCollectorCircles.o Utils/Calibration/PointsCollectorCircles.cpp

build/Debug/GNU-Linux/utils.o: Utils/Calibration/utils.cpp Utils/Calibration/utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/utils.o Utils/Calibration/utils.cpp

build/Debug/GNU-Linux/FieldOfViewChecker.o: Utils/FieldOfViewChecker.cpp Utils/FieldOfViewChecker.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/FieldOfViewChecker.o Utils/FieldOfViewChecker.cpp

build/Debug/GNU-Linux/ImageTransformation.o: Utils/ImageProcessing/ImageTransformation.cpp Utils/ImageProcessing/ImageTransformation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/ImageTransformation.o Utils/ImageProcessing/ImageTransformation.cpp

build/Debug/GNU-Linux/FalseColor.o: Utils/ImagesColor/FalseColor.cpp Utils/ImagesColor/FalseColor.h \
		Utils/ImagesColor/LutTables.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/FalseColor.o Utils/ImagesColor/FalseColor.cpp

build/Debug/GNU-Linux/main.o: main.cpp GUI/MainMenuWindow.h \
		ui_MainMenuWindow.h \
		GUI/CalibrationExecutor.h \
		ui_CalibrationExecutor.h \
		GUI/Cameras/CameraViewer.h \
		ui_CameraViewer.h \
		GUI/Cameras/ImageViewer.h \
		ui_ImageViewer.h \
		Utils/ImageProcessing/ImageTransformation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/main.o main.cpp

build/Debug/GNU-Linux/moc_CalibrationExecutor.o: moc_CalibrationExecutor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/moc_CalibrationExecutor.o moc_CalibrationExecutor.cpp

build/Debug/GNU-Linux/moc_CameraViewer.o: moc_CameraViewer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/moc_CameraViewer.o moc_CameraViewer.cpp

build/Debug/GNU-Linux/moc_ImageViewer.o: moc_ImageViewer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/moc_ImageViewer.o moc_ImageViewer.cpp

build/Debug/GNU-Linux/moc_MainMenuWindow.o: moc_MainMenuWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/moc_MainMenuWindow.o moc_MainMenuWindow.cpp

build/Debug/GNU-Linux/moc_CameraCalibration.o: moc_CameraCalibration.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/moc_CameraCalibration.o moc_CameraCalibration.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

