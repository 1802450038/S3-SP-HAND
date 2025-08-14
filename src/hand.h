#ifndef HAND_H
#define HAND_H

extern int THUMB_POS;
extern int INDEX_POS;
extern int MIDDLE_POS;
extern int RING_POS;
extern int LITTLE_POS;
extern int GESTURE;
extern int ACTION_MODE;
extern bool HAND_STATE;
extern bool FEEDBACK_STATE;


int setFingerPos(int finger, int value);
void setGesture(int value);
void setHandState(bool value);
void setFeedbackState(bool value);

#endif