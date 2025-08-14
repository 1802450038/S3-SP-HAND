#include <Arduino.h>
#include "hand.h"

int THUMB_POS = 0;
int INDEX_POS = 0;
int MIDDLE_POS = 0;
int RING_POS = 0;
int LITTLE_POS = 0;
int GESTURE = 0;
int ACTION_MODE = 0;
bool HAND_STATE = false;
bool FEEDBACK_STATE = false;

/*
Atualiza a variavél responsavel por controlara a posição dos dedos com base em valor
analogico recebido e convertido para uma faixa de angulo entre 0 e 180
*/ 
int setFingerPos(int finger, int value)
{
    int angle = map(value, 0, 4096, 180, 0);
    switch (finger)
    {
    case 0:
        THUMB_POS = angle;
        break;
    case 1:
        INDEX_POS = angle;
        break;
    case 2:
        MIDDLE_POS = angle;
        break;
    case 3:
        RING_POS = angle;
        break;
    case 4:
        LITTLE_POS = angle;
        break;
    default:
        break;
    }
    return angle;
}

// Atualiza a variavel GESTURE conforme o valor recebido
void setGesture(int value)
{
    GESTURE = value;
}

// Atualiza a variavel HAND_STATE conforme o valor recebido
void setHandState(bool value)
{
    HAND_STATE = value;
}


// Atualiza a variavel FEEDBACK_STATE conforme o valor recebido
void setFeedbackState(bool value)
{
    FEEDBACK_STATE = value;
}