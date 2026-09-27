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



/* RCC base address */
#define     RCC_BASE               0x40023800UL

/* RCC APB1 register offset */
#define     RCC_APB1ENR_OFFSET     0x40UL
#define     RCC_AHB1ENR_OFFSET     0x30UL
#define     RCC_APB2ENR_OFFSET     0x44UL

/* RCC APB1ENR register */
#define     RCC_APB1ENR            (*(volatile uint32_t *)(RCC_BASE + RCC_APB1ENR_OFFSET))
#define     RCC_AHB1ENR            (*(volatile uint32_t *)(RCC_BASE + RCC_AHB1ENR_OFFSET))
#define     RCC_APB2ENR            (*(volatile uint32_t *)(RCC_BASE + RCC_APB2ENR_OFFSET))

/* GPIO A base address */
#define     GPIOA_BASE             0x40020000UL

/* GPIO Registers offset */
#define     GPIO_MODER_OFFSET      0x00UL
#define     GPIO_AFRL_OFFSET       0x20UL
#define     GPIO_PUPDR_OFFSET      0x0CUL

/* GPIOA Registers */
#define     GPIOA_MODER            (*(volatile uint32_t *)(GPIOA_BASE + GPIO_MODER_OFFSET))
#define     GPIOA_AFRL             (*(volatile uint32_t *)(GPIOA_BASE + GPIO_AFRL_OFFSET))
#define     GPIOA_PUPDR            (*(volatile uint32_t *)(GPIOA_BASE + GPIO_PUPDR_OFFSET))

/* UART2 base address */
#define     UART2_BASE             0x40004400UL

/* UART2 register offset */
#define     UART2_SR_OFFSET        0x00UL
#define     UART2_DR_OFFSET        0x04UL
#define     UART2_BRR_OFFSET       0x08UL
#define     UART2_CR1_OFFSET       0x0CUL
#define     UART2_CR2_OFFSET       0x10UL


/* UART2 registers */
#define     UART2_SR               (*(volatile uint32_t *)(UART2_BASE + UART2_SR_OFFSET))
#define     UART2_DR               (*(volatile uint32_t *)(UART2_BASE + UART2_DR_OFFSET))
#define     UART2_BRR              (*(volatile uint32_t *)(UART2_BASE + UART2_BRR_OFFSET))
#define     UART2_CR1              (*(volatile uint32_t *)(UART2_BASE + UART2_CR1_OFFSET))
#define     UART2_CR2              (*(volatile uint32_t *)(UART2_BASE + UART2_CR2_OFFSET))

/* ADC1 base address */
#define     ADC1_BASE              0x40012000UL

/* ADC1 registers offset */
#define     ADC1_SR_OFFSET         0x00UL
#define     ADC1_DR_OFFSET         0x4CUL
#define     ADC1_CCR_OFFSET        0x304UL
#define     ADC1_CR1_OFFSET        0x04UL
#define     ADC1_SQR1_OFFSET       0x2CUL
#define     ADC1_SQR3_OFFSET       0x34UL
#define     ADC1_SMPR2_OFFSET      0x10UL
#define     ADC1_CR2_OFFSET        0x08UL

/* ADC1 registers */
#define     ADC1_SR                (*(volatile uint32_t *)(ADC1_BASE + ADC1_SR_OFFSET))
#define     ADC1_DR                (*(volatile uint32_t *)(ADC1_BASE + ADC1_DR_OFFSET))
#define     ADC1_CCR               (*(volatile uint32_t *)(ADC1_BASE + ADC1_CCR_OFFSET))
#define     ADC1_CR1               (*(volatile uint32_t *)(ADC1_BASE + ADC1_CR1_OFFSET))
#define     ADC1_CR2               (*(volatile uint32_t *)(ADC1_BASE + ADC1_CR2_OFFSET))
#define     ADC1_SQR1              (*(volatile uint32_t *)(ADC1_BASE + ADC1_SQR1_OFFSET))
#define     ADC1_SQR3              (*(volatile uint32_t *)(ADC1_BASE + ADC1_SQR3_OFFSET))
#define     ADC1_SMPR2             (*(volatile uint32_t *)(ADC1_BASE + ADC1_SMPR2_OFFSET))

/* SysTick registers */
#define     SYST_CSR               (*(volatile uint32_t *)0xE000E010U)
#define     SYST_RVR               (*(volatile uint32_t *)0xE000E014U)
#define     SYST_CVR               (*(volatile uint32_t *)0xE000E018U)

/* NVIC base address */
#define     NVIC_BASE              0xE000E100UL

/* NVIC registers offset */
#define     NVIC_ISER0_OFFSET      0x00UL

/* NVIC registers */
#define     NVIC_ISER0             (*(volatile uint32_t *)(NVIC_BASE + NVIC_ISER0_OFFSET))

#endif
