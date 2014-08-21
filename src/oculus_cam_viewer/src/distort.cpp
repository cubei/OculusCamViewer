/**
 * @Author Lars Harmsen
 */

#include "distort.h"
#include <opencv/cv.h>

cv::Mat barrel_dist(cv::Mat* img, float Cx, float Cy, float k0, float k1, float k2, float scale) {
	cv::Mat* mapx = new cv::Mat(img->rows, img->cols, CV_32FC1);
	cv::Mat* mapy = new cv::Mat(img->rows, img->cols, CV_32FC1);
	
	float* pbufx = (float*)mapx->data;
	float* pbufy = (float*)mapy->data;

	const float unit_xr2 = (img->cols/2) * (img->cols/2);
	const float unit_yr2 = (img->rows/2) * (img->rows/2);

	for (int y = 0; y < img->rows; y++) {
		for (int x = 0; x < img->cols; x++) {

			const float r2 = (x-Cx)*(x-Cx)+(y-Cy)*(y-Cy);

			const float r2x = r2 / unit_xr2;
			const float r4x = r2x * r2x;
			const float r2y = r2 / unit_yr2;
			const float r4y = r2y * r2y;

			*pbufx = Cx + (x - Cx) * (k0 + k1 * r2x + k2 * r4x) * scale;
			*pbufy = Cy + (y - Cy) * (k0 + k1 * r2y + k2 * r4y) * scale;
			
			++pbufx;
			++pbufy;
		}
	}

	cv::Mat dst;
	cv::remap(*img, dst, *mapx, *mapy, CV_INTER_LINEAR);
	mapx->release();
	mapy->release();
	return dst;
}

void create_maps(cv::Mat* mapx, cv::Mat* mapy, float Cx, float Cy, float k0, float k1, float k2, float scale) {
	float* pbufx = (float*)mapx->data;
	float* pbufy = (float*)mapy->data;

	const float unit_xr2 = (mapx->cols/2) * (mapx->cols/2);
	const float unit_yr2 = (mapy->rows/2) * (mapy->rows/2);

	for (int y = 0; y < mapx->rows; y++) {
		for (int x = 0; x < mapx->cols; x++) {

			const float r2 = (x-Cx)*(x-Cx)+(y-Cy)*(y-Cy);

			const float r2x = r2 / unit_xr2;
			const float r4x = r2x * r2x;
			const float r2y = r2 / unit_yr2;
			const float r4y = r2y * r2y;

			*pbufx = Cx + (x - Cx) * (k0 + k1 * r2x + k2 * r4x) * scale;
			*pbufy = Cy + (y - Cy) * (k0 + k1 * r2y + k2 * r4y) * scale;
			
			++pbufx;
			++pbufy;
		}
	}
}


cv::Mat barrel_dist(cv::Mat* img, cv::Mat* mapx, cv::Mat* mapy) {
	cv::Mat dst;
	cv::remap(*img, dst, *mapx, *mapy, CV_INTER_LINEAR);
	return dst;
}