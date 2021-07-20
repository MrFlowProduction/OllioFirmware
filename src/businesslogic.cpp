#include <businesslogic.h>



void stateMachine(){

    return;

    switch (statePoint)
    {

        case NONE:
            
            break;

        case START:
            
            break;

        case SHORTING:
            ShortingState();
            break;

        case SEPARATE:
            
            break;

        case MEASURE:
            
            break;
        
        case PRINTING:
            
            break;
        
        case CLOSING:
            ClosingState();
            break;
        
        case FAULT:
            
            break;

        default:
            break;
    }

}


void ClosingState(){
    task_scale_isEnabled = false;
    task_ads_isEnabled = false;
    tapState = CLOSED;
}


void NoneState(){

    // Change state
    if(isButtonPressed){
        isButtonPressed = false;

        m_counter = 0;
        progress = 0;
        statePoint = MEASURE;
    }
}


void ShortingState(){
    
    if(m_counter == 0){
        m_counter = 0;
        progress = 0;
    }
}



void SeparateState(){

}


void MeasState(){

}


void PrintingState(){


}


void FaultState(){

}


