/**
 * @Author Lars Harmsen
 */
 
#ifndef __OCULUS_VIEWER_DISTORT_H__
#define __OCULUS_VIEWER_DISTORT_H__

#include <opencv2/core/core.hpp>
#include "ImageViewer.h"

#define DISTORT_K0_DEFAULT 1.0f
#define DISTORT_K1_DEFAULT 0.22f
#define DISTORT_K2_DEFAULT 0.24f

#define EYE_POSITION_X_DEFAULT (WINDOW_WIDTH_DEFAULT>>2)
#define EYE_POSITION_Y_DEFAULT (WINDOW_HEIGHT_DEFAULT>>1)

cv::Mat barrel_dist(cv::Mat* img, float Cx = EYE_POSITION_X_DEFAULT, float Cy = EYE_POSITION_Y_DEFAULT,
					float k0 = DISTORT_K0_DEFAULT, float k1 = DISTORT_K1_DEFAULT, float k2 = DISTORT_K2_DEFAULT,
					float scale = 0.8f);

cv::Mat barrel_dist(cv::Mat* img, cv::Mat* mapx, cv::Mat* mapy);

void create_maps(cv::Mat* mapx, cv::Mat* mapy, float Cx = EYE_POSITION_X_DEFAULT, float Cy = EYE_POSITION_Y_DEFAULT,
					float k0 = DISTORT_K0_DEFAULT, float k1 = DISTORT_K1_DEFAULT, float k2 = DISTORT_K2_DEFAULT,
					float scale = 0.8f);

#endif  // __OCULUS_VIEWER_DISTORT_H__

