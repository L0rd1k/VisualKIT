#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as
QMAKE=qmake

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES=


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath,'/usr/local/opencv_3.4.7/lib' /usr/local/opencv_3.4.7/lib/libopencv_aruco.so /usr/local/opencv_3.4.7/lib/libopencv_bgsegm.so /usr/local/opencv_3.4.7/lib/libopencv_bioinspired.so /usr/local/opencv_3.4.7/lib/libopencv_calib3d.so /usr/local/opencv_3.4.7/lib/libopencv_ccalib.so /usr/local/opencv_3.4.7/lib/libopencv_core.so /usr/local/opencv_3.4.7/lib/libopencv_datasets.so /usr/local/opencv_3.4.7/lib/libopencv_dnn.so /usr/local/opencv_3.4.7/lib/libopencv_dnn_objdetect.so /usr/local/opencv_3.4.7/lib/libopencv_dpm.so /usr/local/opencv_3.4.7/lib/libopencv_face.so /usr/local/opencv_3.4.7/lib/libopencv_features2d.so /usr/local/opencv_3.4.7/lib/libopencv_flann.so /usr/local/opencv_3.4.7/lib/libopencv_fuzzy.so /usr/local/opencv_3.4.7/lib/libopencv_hfs.so /usr/local/opencv_3.4.7/lib/libopencv_highgui.so /usr/local/opencv_3.4.7/lib/libopencv_img_hash.so /usr/local/opencv_3.4.7/lib/libopencv_imgcodecs.so /usr/local/opencv_3.4.7/lib/libopencv_imgproc.so /usr/local/opencv_3.4.7/lib/libopencv_line_descriptor.so /usr/local/opencv_3.4.7/lib/libopencv_ml.so /usr/local/opencv_3.4.7/lib/libopencv_objdetect.so /usr/local/opencv_3.4.7/lib/libopencv_optflow.so /usr/local/opencv_3.4.7/lib/libopencv_phase_unwrapping.so /usr/local/opencv_3.4.7/lib/libopencv_photo.so /usr/local/opencv_3.4.7/lib/libopencv_plot.so /usr/local/opencv_3.4.7/lib/libopencv_reg.so /usr/local/opencv_3.4.7/lib/libopencv_rgbd.so /usr/local/opencv_3.4.7/lib/libopencv_saliency.so /usr/local/opencv_3.4.7/lib/libopencv_sfm.so /usr/local/opencv_3.4.7/lib/libopencv_shape.so /usr/local/opencv_3.4.7/lib/libopencv_stereo.so /usr/local/opencv_3.4.7/lib/libopencv_stitching.so /usr/local/opencv_3.4.7/lib/libopencv_structured_light.so /usr/local/opencv_3.4.7/lib/libopencv_superres.so /usr/local/opencv_3.4.7/lib/libopencv_surface_matching.so /usr/local/opencv_3.4.7/lib/libopencv_text.so /usr/local/opencv_3.4.7/lib/libopencv_tracking.so /usr/local/opencv_3.4.7/lib/libopencv_video.so /usr/local/opencv_3.4.7/lib/libopencv_videoio.so /usr/local/opencv_3.4.7/lib/libopencv_videostab.so /usr/local/opencv_3.4.7/lib/libopencv_xfeatures2d.so /usr/local/opencv_3.4.7/lib/libopencv_ximgproc.so /usr/local/opencv_3.4.7/lib/libopencv_xobjdetect.so /usr/local/opencv_3.4.7/lib/libopencv_xphoto.so

nbproject/qt-${CND_CONF}.mk: nbproject/qt-${CND_CONF}.pro FORCE
	${QMAKE} VPATH=. -o qttmp-${CND_CONF}.mk nbproject/qt-${CND_CONF}.pro
	mv -f qttmp-${CND_CONF}.mk nbproject/qt-${CND_CONF}.mk

FORCE:

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} nbproject/qt-${CND_CONF}.mk
	"${MAKE}" -f nbproject/qt-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/VisualKitStream

${CND_BUILDDIR}/Debug/%.o: nbproject/qt-${CND_CONF}.mk
	${MAKE} -f nbproject/qt-${CND_CONF}.mk "$@"

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS} nbproject/qt-${CND_CONF}.mk
	${MAKE} -f nbproject/qt-${CND_CONF}.mk distclean

# Subprojects
.clean-subprojects:
