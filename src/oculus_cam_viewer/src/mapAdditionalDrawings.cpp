/**
 * @Author Lars Harmsen
 */

#include "mapAdditionalDrawings.h"

#include <cmath>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void drawArrow(cv::Mat *img, int size) {
	cv::Point points[1][3];
	points[0][0] = cv::Point((img->cols)>>1,
							(int)(((img->cols)>>1) - size)); // top
	points[0][1] = cv::Point((int)(((img->cols)>>1) - size / 2),
							(int)(((img->cols)>>1) + size)); // left
	points[0][2] = cv::Point((int)(((img->cols)>>1) + size / 2),
							(int)(((img->cols)>>1) + size)); // right
	const cv::Point* ppt[1] = { points[0] };
	int npt[] = { 3 };
	cv::fillPoly(*img, ppt, npt, 1, cv::Scalar(128));
}

void drawArrow(cv::Mat *img, int size, double angle) {
	cv::Point points[3];
	points[0] = cv::Point(((img->cols)>>1) + size * sin(angle),((img->rows)>>1) + size * cos(angle)); // top
	points[1] = cv::Point(((img->cols)>>1) + size * sin(angle - 2.4),((img->rows)>>1) + size * cos(angle - 2.4)); // left
	points[2] = cv::Point(((img->cols)>>1) + size * sin(angle + 2.4),((img->rows)>>1) + size * cos(angle + 2.4)); // right

	const cv::Point* ppt[1] = { points };
	int npt[] = { 3 };
	cv::fillPoly(*img, ppt, npt, 1, cv::Scalar(128));
}

void drawViewCone(cv::Mat *img, int angle) {
	angle = angle>>1;
	int offset = (int) (tan(angle * 2 * M_PI / 360) * (img->rows>>1));

	cv::Point center = cv::Point((img->cols)>>1, (img->cols)>>1);
	cv::Point left = cv::Point(((img->cols)>>1) - offset, 0);
	cv::Point right = cv::Point(((img->cols)>>1) + offset, 0);

	cv::line(*img, center, left, cv::Scalar(128), 2);
	cv::line(*img, center, right, cv::Scalar(128), 2);
}

void drawCircle(cv::Mat *img, int radius) {
	cv::circle(*img, cv::Point((img->cols)>>1, (img->cols)>>1), radius, cv::Scalar(128), -1);
}
