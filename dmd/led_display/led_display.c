
/* -------------------------------------------------------------------------- */
/* ----------------------------- Includes ----------------------------------- */
/* -------------------------------------------------------------------------- */
#include "led_display.h"

#define TIMER                             TIM3
#define RCC_APBxPeriphClockCmd_TIMER      RCC_APB1PeriphClockCmd
#define RCC_APBxPeriph_TIMER              RCC_APB1Periph_TIM3
#define TIMER_IRQn                        TIM3_IRQn
#define TIMER_IRQHandler                  TIM3_IRQHandler
#define TIMER_PRESCALE_DIV  10000 // = timer clock frequency (Hz)
//#define TIMER_PERIOD           10 // 1ms @ 10kHz

static const uint8_t ASCII_Font[ASCII_NB_CHARS][CHAR_WIDTH] = {
   {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, 
   {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, 
   {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, 
   {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, 
   {0x00, 0x00, 0x00, 0x00, 0x00}, //  
   {0x00, 0x00, 0xDE, 0x00, 0x00}, // !
   {0x00, 0x06, 0x00, 0x06, 0x00}, // "
   {0x28, 0xFE, 0x28, 0xFE, 0x28}, // #
   {0x48, 0x54, 0xFE, 0x54, 0x24}, // $
   {0x46, 0x26, 0x10, 0xC8, 0xC4}, // %
   {0x6C, 0x92, 0xAC, 0x40, 0xA0}, // &
   {0x00, 0x00, 0x00, 0x06, 0x00}, // '
   {0x00, 0x38, 0x44, 0x82, 0x00}, // (
   {0x00, 0x82, 0x44, 0x38, 0x00}, // )
   {0x28, 0x10, 0x7C, 0x10, 0x28}, // *
   {0x10, 0x10, 0x7C, 0x10, 0x10}, // +
   {0x00, 0xA0, 0x60, 0x00, 0x00}, // ,
   {0x10, 0x10, 0x10, 0x10, 0x10}, // -
   {0x00, 0xC0, 0xC0, 0x00, 0x00}, // .
   {0x40, 0x20, 0x10, 0x08, 0x04}, // /
   {0x7C, 0xA2, 0x92, 0x8A, 0x7C}, // 0
   {0x00, 0x84, 0xFE, 0x80, 0x00}, // 1
   {0x84, 0xC2, 0xA2, 0x92, 0x8C}, // 2
   {0x42, 0x82, 0x8A, 0x96, 0x62}, // 3
   {0x30, 0x28, 0x24, 0xFE, 0x20}, // 4
   {0x4E, 0x8A, 0x8A, 0x8A, 0x72}, // 5
   {0x78, 0x94, 0x92, 0x92, 0x60}, // 6
   {0x02, 0xE2, 0x12, 0x0A, 0x06}, // 7
   {0x6C, 0x92, 0x92, 0x92, 0x6C}, // 8
   {0x0C, 0x92, 0x92, 0x52, 0x3C}, // 9
   {0x00, 0x6C, 0x6C, 0x00, 0x00}, // :
   {0x00, 0xAC, 0x6C, 0x00, 0x00}, // ;
   {0x10, 0x28, 0x44, 0x82, 0x00}, // <
   {0x28, 0x28, 0x28, 0x28, 0x28}, // =
   {0x00, 0x82, 0x44, 0x28, 0x10}, // >
   {0x04, 0x02, 0xA2, 0x12, 0x0C}, // ?
   {0x7C, 0x82, 0xBA, 0x92, 0x1C}, // @
   {0xFC, 0x12, 0x12, 0x12, 0xFC}, // A
   {0xFE, 0x92, 0x92, 0x92, 0x6C}, // B
   {0x7C, 0x82, 0x82, 0x82, 0x44}, // C
   {0xFE, 0x82, 0x82, 0x82, 0x7C}, // D
   {0xFE, 0x92, 0x92, 0x92, 0x82}, // E
   {0xFE, 0x12, 0x12, 0x12, 0x02}, // F
   {0x7C, 0x82, 0x92, 0x92, 0xF4}, // G
   {0xFE, 0x10, 0x10, 0x10, 0xFE}, // H
   {0x82, 0x82, 0xFE, 0x82, 0x82}, // I
   {0x40, 0x80, 0x82, 0x7E, 0x02}, // J
   {0xFE, 0x10, 0x28, 0x44, 0x82}, // K
   {0xFE, 0x80, 0x80, 0x80, 0x80}, // L
   {0xFE, 0x04, 0x18, 0x04, 0xFE}, // M
   {0xFE, 0x08, 0x10, 0x20, 0xFE}, // N
   {0x7C, 0x82, 0x82, 0x82, 0x7C}, // O
   {0xFE, 0x12, 0x12, 0x12, 0x0C}, // P
   {0x7C, 0x82, 0xA2, 0x42, 0xBC}, // Q
   {0xFE, 0x12, 0x32, 0x52, 0x8C}, // R
   {0x8C, 0x92, 0x92, 0x92, 0x62}, // S
   {0x02, 0x02, 0xFE, 0x02, 0x02}, // T
   {0x7E, 0x80, 0x80, 0x80, 0x7E}, // U
   {0x1E, 0x60, 0x80, 0x60, 0x1E}, // V
   {0x7E, 0x80, 0x70, 0x80, 0x7E}, // W
   {0xC6, 0x28, 0x10, 0x28, 0xC6}, // X
   {0x0E, 0x10, 0xE0, 0x10, 0x0E}, // Y
   {0xC2, 0xA2, 0x92, 0x8A, 0x86}, // Z
   {0x00, 0xFE, 0x82, 0x00, 0x00}, // [
   {0x04, 0x08, 0x10, 0x20, 0x40}, // \ //
   {0x00, 0x00, 0x82, 0xFE, 0x00}, // ]
   {0x08, 0x04, 0x02, 0x04, 0x08}, // ^
   {0x80, 0x80, 0x80, 0x80, 0x80}, // _
   {0x02, 0x04, 0x08, 0x00, 0x00}, // `
   {0x40, 0xA8, 0xA8, 0xA8, 0xF0}, // a
   {0xFE, 0x90, 0x88, 0x88, 0x70}, // b
   {0x70, 0x88, 0x88, 0x88, 0x40}, // c
   {0x70, 0x88, 0x88, 0x90, 0xFE}, // d
   {0x70, 0xA8, 0xA8, 0xA8, 0x30}, // e
   {0x10, 0xFC, 0x12, 0x02, 0x04}, // f
   {0x18, 0xA4, 0xA4, 0xA4, 0x7C}, // g
   {0xFE, 0x10, 0x08, 0x08, 0xF0}, // h
   {0x00, 0x88, 0xFA, 0x80, 0x00}, // i
   {0x40, 0x80, 0x88, 0x7A, 0x00}, // j
   {0xFE, 0x20, 0x50, 0x88, 0x00}, // k
   {0x00, 0x82, 0xFE, 0x80, 0x00}, // l
   {0xF8, 0x08, 0x30, 0x08, 0xF0}, // m
   {0xF8, 0x10, 0x08, 0x08, 0xF0}, // n
   {0x70, 0x88, 0x88, 0x88, 0x70}, // o
   {0xF8, 0x28, 0x28, 0x28, 0x10}, // p
   {0x10, 0x28, 0x28, 0x30, 0xF8}, // q
   {0xF8, 0x10, 0x08, 0x08, 0x10}, // r
   {0x90, 0xA8, 0xA8, 0xA8, 0x40}, // s
   {0x08, 0x7E, 0x88, 0x80, 0x40}, // t
   {0x78, 0x80, 0x80, 0x40, 0xF8}, // u
   {0x38, 0x40, 0x80, 0x40, 0x38}, // v
   {0x78, 0x80, 0x60, 0x80, 0x78}, // w
   {0x88, 0x50, 0x20, 0x50, 0x88}, // x
   {0x18, 0xA0, 0xA0, 0xA0, 0x78}, // y
   {0x88, 0xC8, 0xA8, 0x98, 0x88}, // z
   {0x10, 0x6C, 0x82, 0x82, 0x00}, // {
   {0x00, 0x00, 0xFE, 0x00, 0x00}, // |
   {0x00, 0x82, 0x82, 0x6C, 0x10}, // }
   {0x04, 0x02, 0x04, 0x08, 0x04}, // ~
   {0}, 
   // {0xFE, 0x92, 0x93, 0x92, 0x82}, // �
};

static char * str = 0;
static unsigned int len = 0;
static unsigned int no_char = 0;
static unsigned int no_col = 0;

/* -------------------------------------------------------------------------- */
/* ------------------------ Private prototypes ------------------------------ */
/* -------------------------------------------------------------------------- */

static uint8_t Get_Column_Value(void);
static void Display_Column(void);

static void RCC_Configuration(void);
static void TIM_Configuration(uint16_t Timer_Period);
static void NVIC_Configuration(void);

/* -------------------------------------------------------------------------- */
/* ------------------------- Public functions ------------------------------- */
/* -------------------------------------------------------------------------- */

void LED_Display_Config(char * string, unsigned int length, uint16_t period) {
   /* System clocks configuration */
   RCC_Configuration();

   /* Configure the TIM ports */
   TIM_Configuration(period);

   /* NVIC configuration */
   NVIC_Configuration();

   /* Initialize LEDs */
   LEDs_Config();
   LED_Display_Set_String(string, length);
   // Display_Column();
}

void LED_Display_Set_String(char * string, unsigned int length) {
   str = string;
   len = length;
}

void LED_Display_Start(void) {
   TIM_Cmd(TIMER, ENABLE);    // timer counter enable
}

void LED_Display_Stop(void) {
   TIM_Cmd(TIMER, DISABLE);   // timer counter disable
}

/* -------------------------------------------------------------------------- */
/* ------------------------- Private functions ------------------------------ */
/* -------------------------------------------------------------------------- */

uint8_t Get_Column_Value(void) {
   return ASCII_Font[str[no_char]][no_col];
}

void Display_Column(void) {
   LEDs_Write(Get_Column_Value());
}

void TIMER_IRQHandler(void) {
   TIM_ClearITPendingBit(TIMER, TIM_IT_Update);

   if(++no_col == CHAR_WIDTH) {
      no_col = 0;
      no_char = (no_char + 1) % len;
   }

   Display_Column();
}

void RCC_Configuration(void) {
   /* TIMER clock enable */
   RCC_APBxPeriphClockCmd_TIMER(RCC_APBxPeriph_TIMER, ENABLE);
}

void TIM_Configuration(uint16_t Timer_Period) {
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
   uint16_t PrescalerValue;

   /* Compute the prescaler value */
   PrescalerValue = (uint16_t)(SystemCoreClock / TIMER_PRESCALE_DIV);

   /* Time base configuration */
   TIM_TimeBaseStructure.TIM_Period = Timer_Period-1;
   TIM_TimeBaseStructure.TIM_Prescaler = 0;
   TIM_TimeBaseStructure.TIM_ClockDivision = 0;
   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;

   TIM_TimeBaseInit(TIMER, &TIM_TimeBaseStructure);

   /* Prescaler configuration */
   TIM_PrescalerConfig(TIMER, PrescalerValue-1, TIM_PSCReloadMode_Immediate);

   /* TIM IT enable */
   TIM_ITConfig(TIMER, TIM_IT_Update, ENABLE);
}

void NVIC_Configuration(void) {
   NVIC_InitTypeDef NVIC_InitStructure;

   /* Enable the timer global interrupt */
   NVIC_InitStructure.NVIC_IRQChannel = TIMER_IRQn;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
}
