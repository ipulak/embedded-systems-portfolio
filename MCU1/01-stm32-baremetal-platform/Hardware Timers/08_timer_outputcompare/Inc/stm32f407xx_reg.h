/**
 * @file      stm32f407xx_reg.h
 * @brief     STM32F407 register-level peripheral definitions.
 *
 * @details
 * This header provides register address definitions and memory-mapped
 * register access macros for the STM32F407 micro-controller.
 *
 * The definitions are based on the STM32F407 reference manual (RM0090)
 *
 * @note
 * This file is intended for bare-metal firmware development and does
 * not use the STM32 HAL peripheral Drivers.
 *
 * @author     Pulak Mukherjee
 * @date       2026-08-27
 *
 */

#ifndef     STM32F407XX_REG_H
#define     STM32F407XX_REG_H


#include <stdint.h>


/* Configure TIM2 base address */
#define      TIM2_BASE             0x40000000UL

/* 	TIM2 registers offset */
#define      TIM2_CR1_OFFSET       0x00UL
#define      TIM2_SR_OFFSET        0x10UL
#define      TIM2_ARR_OFFSET       0x2CUL
#define      TIM2_PSC_OFFSET       0x28UL
#define      TIM2_CNT_OFFSET       0x24UL
#define      TIM2_CCMR1_OFFSET     0x18UL
#define      TIM2_CCER_OFFSET      0x20UL

/* TIM2 registers */
#define      TIM2_CR1              (*(volatile uint32_t *)(TIM2_BASE + TIM2_CR1_OFFSET))
#define      TIM2_SR               (*(volatile uint32_t *)(TIM2_BASE + TIM2_SR_OFFSET))
#define      TIM2_ARR              (*(volatile uint32_t *)(TIM2_BASE + TIM2_ARR_OFFSET))
#define      TIM2_PSC              (*(volatile uint32_t *)(TIM2_BASE + TIM2_PSC_OFFSET))
#define      TIM2_CNT              (*(volatile uint32_t *)(TIM2_BASE + TIM2_CNT_OFFSET))
#define      TIM2_CCMR1            (*(volatile uint32_t *)(TIM2_BASE + TIM2_CCMR1_OFFSET))
#define      TIM2_CCER             (*(volatile uint32_t *)(TIM2_BASE + TIM2_CCER_OFFSET))

/* RCC base address */
#define      RCC_BASE              0x40023800UL

/* RCC offset registers */
#define      RCC_AHB1ENR_OFFSET    0x30UL
#define      RCC_APB1ENR_OFFSET    0x40UL

/* RCC AHB1ENR register */
#define      RCC_AHB1ENR           (*(volatile uint32_t *)(RCC_BASE + RCC_AHB1ENR_OFFSET))
#define      RCC_APB1ENR           (*(volatile uint32_t *)(RCC_BASE + RCC_APB1ENR_OFFSET))

/* GPIO PORT A base address */
#define      GPIOA_BASE            0x40020000UL

/* GPIO register offset */
#define      GPIOA_MODER_BASE      0x00UL
#define      GPIOA_ODR_OFFSET      0x14UL
#define      GPIOA_AFRL_OFFSET     0x20UL

/* GPIOA registers */
#define      GPIOA_MODER           (*(volatile uint32_t *)(GPIOA_BASE + GPIOA_MODER_BASE))
#define      GPIOA_ODR             (*(volatile uint32_t *)(GPIOA_BASE + GPIOA_ODR_OFFSET))
#define      GPIOA_AFRL            (*(volatile uint32_t *)(GPIOA_BASE + GPIOA_AFRL_OFFSET))

#endif
