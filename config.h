#define PI 3.14159265359
#define DEG2RAD 3.14159265359/180
#define RAD2DEG 180/3.14159265359
#define fordFusionLength 3 //ford fusion car length
#define dt .1 //simulation sample time [sec]
#define simulationTime 200
// Localization INS noise specification:
#define gpsStdPos 0.1 // Adding GPS white noise to position with standard deviation of 0.1[meter]
#define gpsStdAng 0.01 // Adding GPS white noise to orientation with standard deviation of 0.01[rad]
// SERVO actuator specification
#define specLamdaAngLimiter  45*DEG2RAD  // wheel angle mechanical limit is 45[degress]
#define specLlamdaRateLimiter  20*DEG2RAD  // wheel rate limit is 20[deg/sec]
#define isLocalizationErr false

