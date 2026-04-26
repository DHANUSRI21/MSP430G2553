#include <msp430.h>
#include "ADC.h"

void delay_ms(unsigned int ms)
{
    while(ms--) __delay_cycles(1000);
}

void set_forward_dir()
{
    P2OUT |= BIT1;
    P2OUT &= ~BIT5;
}

void stop_bot()
{
    TA1CCR1 = 0;
    TA1CCR2 = 0;
}

void forward()
{
    set_forward_dir();
    TA1CCR1 = 700;
    TA1CCR2 = 700;
}

void left_turn()
{
    stop_bot();
    set_forward_dir();

    TA1CCR1 = 0;
    TA1CCR2 = 800;

    delay_ms(980);
    stop_bot();
}

void right_turn()
{
    stop_bot();
    set_forward_dir();

    TA1CCR1 = 800;
    TA1CCR2 = 0;

    delay_ms(980);
    stop_bot();
}

int read_adc(int ch)
{
    ADC_Demarrer_conversion(ch);
    return ADC_Lire_resultat();
}

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;

    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL  = CALDCO_1MHZ;

    P2DIR |= BIT1 | BIT2 | BIT4 | BIT5;
    P2SEL |= BIT2 | BIT4 ;
    P2SEL2 &= ~(BIT2 | BIT4);

    // Enable ADC pins (front, left, light)
    P1DIR &= ~(BIT3 | BIT4 | BIT6);
    P1SEL |= BIT3 | BIT4 | BIT6;
    P1SEL2 |= BIT3 | BIT4 | BIT6;

    TA1CCR0 = 1000;
    TA1CCTL1 = OUTMOD_7;
    TA1CCTL2 = OUTMOD_7;
    TA1CTL = TASSEL_2 | MC_1;

    ADC_init();

    while(1)
    {
        int front = read_adc(3);
        int left  = read_adc(4);
        int light = read_adc(6);

        int threshold = 700;
        int threshold1 = 700;
        int LIGHT_TH = 250;

        if(light < LIGHT_TH)
        {
            stop_bot();
        }
        else
        {
            if(front < threshold)
            {
                forward();
            }
            else
            {
                stop_bot();
                delay_ms(200);

                if(left < threshold1)
                {
                    left_turn();
                }
                else
                {
                    right_turn();
                }
            }
        }

        delay_ms(20);
    }
}
