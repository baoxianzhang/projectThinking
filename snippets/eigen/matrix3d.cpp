// TODO
#include <>

Matrix3d covariance;
covariance.fill(0.);
covariance(0, 0) = transNoise[0]*transNoise[0];
covariance(1, 1) = transNoise[1]*transNoise[1];
covariance(2, 2) = rotNoise*rotNoise;
Matrix3d information = covariance.inverse();
