#include <adc.h>
#include <businesslogic.h>
#include <scale.h>
#include <globals.h>
#include <expander.h>



void stateMachine(){

    return;

    switch (statePoint)
    {

        case NONE:
            
            break;

        case START:
            SystemCheck();
            Reset();
            WaitForButton();
            break;

        case SHORTING:
            ShortingState();
            break;

        case SEPARATE:
            
            break;

        case MEASURE:
            MeasState();
            break;
        
        case PRINTING:
            
            break;
        
        case CLOSING:
            ClosingState();
            break;
        
        case FAULT: // Fedél nyitva üzem közben, szenzor hiba, szelep hiba, kijelző hiba, rendszer hiba
            ErrorState();
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

void WaitForButton()
{
   
    bool checkButton = true;
    
    while(checkButton)
    {
        if (isButtonPressed && !isDoorOpened && !isTankFull){
        statePoint = MEASURE;
        checkButton = false;
        }
    }
    
    
}

void SeparateState(){

}


void MeasState(){
   
   adc_reading();
   
   if (probe_votlage<oilquality_max && probe_votlage>oilquality_min)
   {
        // Oil quality optimal
   }
   else
   {
        // Separation needed
        statePoint=SEPARATE;
   }

}


void PrintingState(){


}


void FaultState(){

}

void SystemCheck(){

}

void Reset(){
    error_code = ERROR_NONE;
}

void ErrorState(){
   
}


