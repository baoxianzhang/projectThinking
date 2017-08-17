#include <opencv2/video/tracking.hpp>

// use the cv::Mat
cv::KalmanFilter kalman_filter = cv::KalmanFilter(3, 3, 3);
setIdentity(kalman_filter_.transitionMatrix);
setIdentity(kalman_filter_.measurementMatrix);
setIdentity(kalman_filter_.controlMatrix);
setIdentity(kalman_filter_.errorCovPost);

kalman_filter.processNoiseCov = cv::Mat::zeros(cv::Size(3, 3), CV_32F);
kalman_filter.processNoiseCov.at<float>(0, 0) = 3.1;
kalman_filter.processNoiseCov.at<float>(1, 1) = 3.1;
kalman_filter.processNoiseCov.at<float>(2, 2) = 0.51;
kalman_filter.measurementNoiseCov = cv::Mat::zeros(cv::Size(3, 3), CV_32F);
kalman_filter.measurementNoiseCov.at<float>(0, 0) = 0.5;
kalman_filter.measurementNoiseCov.at<float>(1, 1) = 0.5;
kalman_filter.measurementNoiseCov.at<float>(2, 2) = 0.1;

cv::Mat control_vector = cv::Mat::zeros(cv::Size(1, 3), CV_32F);
cv::Mat measure_vector = cv::Mat::zeros(cv::Size(1, 3), CV_32F);
kalman_filter.statePost = cv::Mat::zeros(cv::Size(1, 3), CV_32F);

// TODO use the cv::Mat_




// Config use the yaml file
std::string config_file = "some_path/kalman_filter.yaml";
cv::FileStorage config(config_file.c_str(), cv::FileStorage::READ);
kalman_filter.processNoiseCov = cv::Mat::zeros(cv::Size(3, 3), CV_32F);
kalman_filter.measurementNoiseCov = cv::Mat::zeros(cv::Size(3, 3), CV_32F);
config["processNoiseCov"] >> kalman_filter.processNoiseCov;
config["measurementNoiseCov"] >> kalman_filter.measurementNoiseCov;
config.release();


// The config file contain
// %YAML:1.0
// processNoiseCov: !!opencv-matrix
// rows: 3
// cols: 3
// dt: f
// data: [ 5.1,  0.0,  0.0,
//         0.0,  5.1,  0.0,
//         0.0,  0.0,  1.0 ]
// measurementNoiseCov: !!opencv-matrix
// rows: 3
// cols: 3
// dt: f
// data: [ 0.1,  0.0,  0.0,
//         0.0,  0.1,  0.0,
//         0.0,  0.0,  0.1 ]





