/*
 * facedetector.h
 *
 *  Created on: Jul 23, 2013
 *      Author: stk
 */

#ifndef FACEDETECTOR_H_
#define FACEDETECTOR_H_

#include <opencv2/opencv.hpp>

using namespace cv;

namespace facecrop {

class FaceDetector{

protected:
	CascadeClassifier cascade_f;
	bool autoEqualize;
	bool autoGrayscale;
	/**
	 * \brief Set face area of a face region with the coordinate of the first face found.
	 * @param img
	 * @param faceRegion
	 * @return
	 */
	virtual bool detectFace(Mat & img, Rect & faceRegion);

public:
	/**
	 *
	 * @param face_config_file
	 */
	FaceDetector( string face_config_file );
	virtual ~FaceDetector();
	/**
	 *
	 * @param img
	 * @param faceRegion
	 * @return
	 */
	virtual bool detect(Mat & img , Rect & faceRegion);
};

} /* namespace facecrop */

#endif /* FACEDETECTOR_H_ */