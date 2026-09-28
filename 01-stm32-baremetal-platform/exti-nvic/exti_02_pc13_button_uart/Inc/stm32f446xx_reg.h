/**
 * @file      stm32f446xx_reg.h
 * @brief     STM32F446 register-level peripheral definitions.
 *
 * @details
 * This header provides register address definitions and memory-mapped
 * register access macros for the STM32F446 micro-controller.
 *
 * The definitions are based on the STM32F446 reference manual (RM0390)
 *
 * @note
 * This file is intended for bare-metal firmware development and does
 * not use the STM32 HAL peripheral Drivers.
 *
 * @author     Pulak Mukherjee
 * @date       2026-08-27
 *
 */

#ifndef     STM32F446XX_REG_H
#define     STM32F446XX_REG_H


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

/* SYSCFG base address */
#define     SYSCFG_BASE            0x40013800UL

/* SYSCFG registers offset */
#define     SYSCFG_EXTICR4_OFFSET  0x14UL

/* SYSCFG register */
#define     SYSCFG_EXTICR4         (*(volatile uint32_t *)(SYSCFG_BASE + SYSCFG_EXTICR4_OFFSET))

/* EXTI base address */
#define     EXTI_BASE              0x40013C00UL

/* EXTI registers offset */
#define     EXTI_IMR_OFFSET        0x00UL
#define     EXTI_RTSR_OFFSET       0x08UL
#define     EXTI_FTSR_OFFSET       0x0CUL
#define     EXTI_PR_OFFSET         0x14UL

/* EXTI registers */
#define     EXTI_IMR               (*(volatile uint32_t *)(EXTI_BASE + EXTI_IMR_OFFSET))
#define     EXTI_RTSR               (*(volatile uint32_t *)(EXTI_BASE + EXTI_RTSR_OFFSET))
#define     EXTI_FTSR              (*(volatile uint32_t *)(EXTI_BASE + EXTI_FTSR_OFFSET))
#define     EXTI_PR                (*(volatile uint32_t *)(EXTI_BASE + EXTI_PR_OFFSET))

/* NVIC base address */
#define     NVIC_BASE              0xE000E100UL

/* NVIC registers offset */
#define     NVIC_ISER0_OFFSET      0x00UL
#define     NVIC_ISER1_OFFSET      0x04UL

/* NVIC register address */
#define     NVIC_ISER1             (*(volatile uint32_t *)(NVIC_BASE + NVIC_ISER1_OFFSET))

/* GPIO A base address */
#define     GPIOA_BASE             0x40020000UL

/* GPIO C base address */
#define     GPIOC_BASE             0x40020800UL

/* GPIO Registers offset */
#define     GPIO_MODER_OFFSET      0x00UL
#define     GPIO_AFRL_OFFSET       0x20UL
#define     GPIO_PUPDR_OFFSET      0x0CUL
#define     GPIO_ODR_OFFSET        0x14UL

/* GPIOA Registers */
#define     GPIOA_MODER            (*(volatile uint32_t *)(GPIOA_BASE + GPIO_MODER_OFFSET))
#define     GPIOA_AFRL             (*(volatile uint32_t *)(GPIOA_BASE + GPIO_AFRL_OFFSET))

#define     GPIOA_ODR              (*(volatile uint32_t *)(GPIOA_BASE + GPIO_ODR_OFFSET))

/* GPIOC Registers */
#define     GPIOC_MODER            (*(volatile uint32_t *)(GPIOC_BASE + GPIO_MODER_OFFSET))
#define     GPIOC_PUPDR            (*(volatile uint32_t *)(GPIOC_BASE + GPIO_PUPDR_OFFSET))
#define     GPIOC_ODR              (*(volatile uint32_t *)(GPIOC_BASE + GPIO_ODR_OFFSET))

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

#endif
