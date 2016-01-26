
IF (MSVC)
  # Setting the xecutables as console applications
  SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
ENDIF (MSVC)
# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
#end of uninstall
include_directories(${SRCDIR}/training)
include_directories(${SRCDIR}/facedetector)
include_directories(${SRCDIR}/gaborbank)
include_directories(${SRCDIR}/utils)
include_directories(${SRCDIR}/detector)
include_directories(${SRCDIR}/gui)

SET(EMOTIME_LIB_FILES "")
SET(EMOTIME_H_FILES "")

add_subdirectory(training)
add_subdirectory(facedetector)
add_subdirectory(gaborbank)
add_subdirectory(dataset)
add_subdirectory(utils)
add_subdirectory(detector)
add_subdirectory(gui)

find_package(OpenCV COMPONENTS opencv_core opencv_ml opencv_imgproc
  opencv_highgui opencv_objdetect REQUIRED)

# Emotime library
add_library(emotime SHARED  facedetector/FaceDetector.cpp
                            detector/EmoDetector.cpp
                            detector/BoostEmoDetector.cpp
                            detector/SVMEmoDetector.cpp
                            training/Classifier.cpp
                            training/AdaBoostClassifier.cpp
                            training/SVMClassifier.cpp
                            detector/FacePreProcessor.cpp
                            gaborbank/GaborBank.cpp
                            gaborbank/GaborKernel.h
                            utils/matrix_io.cpp
                            utils/string_utils.cpp
			    gui/ACapture.cpp
			    gui/ACapture.h
			    gui/AGui.cpp
			    gui/AGui.h
           		    gui/EmotimeGui.cpp
           		    gui/EmotimeGui.h
               		    gui/emotimegui_cli.cpp
			    gui/VideoCapture.cpp
			    gui/VideoCapture.h
			    gui/WebcamCapture.h)

target_link_libraries(emotime ${OpenCV_LIBS})

INSTALL(TARGETS emotime DESTINATION lib)

INSTALL(FILES facedetector/FaceDetector.h
               utils/matrix_io.h utils/string_utils.h
               gaborbank/GaborBank.h gaborbank/GaborKernel.h
               detector/EmoDetector.h detector/BoostEmoDetector.h detector/SVMEmoDetector.h detector/FacePreProcessor.h gui/ACapture.h gui/AGui.h gui/EmotimeGui.h gui/VideoCapture.h gui/WebcamCapture.h
               training/Classifier.h training/SVMClassifier.h training/AdaBoostClassifier.h training/TrainingParameters.h 
       DESTINATION include)

