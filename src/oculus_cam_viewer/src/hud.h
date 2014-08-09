/**
 * @Author Lars Harmsen
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int getXPosForRightEye(int lensSeparationDistancePixel, int screenDistancePixel, int screenWidthPixel, int posLeft, float distanceFactor);

int getXPosForLeftEye(int lensSeparationDistancePixel, int screenDistancePixel, int screenWidthPixel, int posRight, float distanceFactor);

void drawImageOnImage(cv::Mat *src, cv::Mat *dst, int posX, int posY, cv::Mat *mask = 0);