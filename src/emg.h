#ifndef EMG_H
#define EMG_H

// EMG Sensor Definitions
#define ANALOG_EMG_1_PIN A4 // EMG 1 Pin
#define ANALOG_POT A1

extern int POT_DIVIDER;
extern int INF_LIMIT;
extern int SUP_LIMIT;
extern int BASE_LIMIT;
extern int EMG_GESTURE;
extern int TIME_OUT;
extern bool debug; // Debug mode
extern unsigned long lastGestureMillis;
extern unsigned long lastToggleMillis;

void incrementGesture(int gestureInterval);
void toggleStateTime(int stateInterval);
bool checkLimitsWithTimeout(int highOut, int lowOut, int highLim, int lowLim, unsigned long timeoutMillis);
void emgLines(bool debug, bool display, int timeOut);
void emgVizualizer(bool debug);
void updateLimiters(int potValue, int potDivider);
void initEMG();
void updateTimeOut(int potValue);
void toggleHandState();
// void emgProcessor(bool debug);
#endif // EMG_H