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
 * @date       2026-08-18
 *
 */


#ifndef  STM32F407XX_REG_H
#define  STM32F407XX_REG_H

#include <stdint.h>

/* RCC Peripheral base address */
#define    RCC_BASE              0x40023800UL

/* RCC AHB1 peripheral clock enable register offset */
#define    RCC_AHB1_OFFSET       0x30UL

/* RCC APB2 peripheral clock enable register offset */
#define    RCC_APB2_OFFSET       0x44UL

/* RCC AHB1 peripheral clock enable register */
#define    RCC_AHB1ENR           (*(volatile uint32_t *)(RCC_BASE + RCC_AHB1_OFFSET))

/* RCC APB2 peripheral clock enable register */
#define    RCC_APB2ENR           (*(volatile uint32_t *)(RCC_BASE + RCC_APB2_OFFSET))

/* GPIO Port A&D peripheral base address */
#define    GPIOD_BASE            0x40020C00UL
#define    GPIOA_BASE            0x40020000UL

/* EXTI base address */
#define    EXTI_BASE             0x40013C00UL

/* EXTI registers offset */
#define    EXTI_IMR_OFFSET       0x00UL
#define    EXTI_RTSR_OFFSET      0x08UL
#define    EXTI_FTSR_OFFSET      0x0CUL
#define    EXTI_PR_OFFSET        0x14UL

/* EXTI registers */
#define    EXTI_IMR              (*(volatile uint32_t *)(EXTI_BASE + EXTI_IMR_OFFSET))

#define    EXTI_RTSR             (*(volatile uint32_t *)(EXTI_BASE + EXTI_RTSR_OFFSET))

#define    EXTI_FTSR             (*(volatile uint32_t *)(EXTI_BASE + EXTI_FTSR_OFFSET))

#define    EXTI_PR               (*(volatile uint32_t *)(EXTI_BASE + EXTI_PR_OFFSET))

/* SYSCFG base address */
#define    SYSCFG_BASE           0x40013800UL

/* SYSCFG EXTICR1 offset */
#define    SYSCFG_EXTICR1_OFFSET 0x08UL

/* SYSCFG EXTICR1 register */
#define    SYSCFG_EXTICR1        (*(volatile uint32_t *)(SYSCFG_BASE + SYSCFG_EXTICR1_OFFSET))

/* GPIO register offsets */
#define    GPIO_MODER_OFFSET    0x00UL
#define    GPIO_OTYPR_OFFSET    0x04UL
#define    GPIO_OSPEEDR_OFFSET  0x08UL
#define    GPIO_PUPDR_OFFSET    0x0CUL
#define    GPIO_BSSR_OFFSET     0x18UL
#define    GPIO_ODR_OFFSET      0x14UL
#define    GPIO_IDR_OFFSET      0X10UL
#define    GPIO_MODER_OFFSET    0x00UL

/* GPIO Port D registers */
#define    GPIOD_MODER           (*(volatile uint32_t *)(GPIOD_BASE + GPIO_MODER_OFFSET))

#define    GPIOD_OTYPR           (*(volatile uint32_t *)(GPIOD_BASE + GPIO_OTYPR_OFFSET))

#define    GPIOD_OSPEEDR         (*(volatile uint32_t *)(GPIOD_BASE + GPIO_OSPEEDR_OFFSET))

#define    GPIOD_PUPDR           (*(volatile uint32_t *)(GPIOD_BASE + GPIO_PUPDR_OFFSET))

#define	   GPIOD_BSSR            (*(volatile uint32_t *)(GPIOD_BASE + GPIO_BSSR_OFFSET))

#define	   GPIOD_ODR             (*(volatile uint32_t *)(GPIOD_BASE + GPIO_ODR_OFFSET))

/* GPIO Port A registers */

#define	   GPIOA_MODER           (*(volatile uint32_t *)(GPIOA_BASE + GPIO_MODER_OFFSET))

#define	   GPIOA_IDR             (*(volatile uint32_t *)(GPIOA_BASE + GPIO_IDR_OFFSET))

#define    GPIOA_PUPDR           (*(volatile uint32_t *)(GPIOA_BASE + GPIO_PUPDR_OFFSET))

/* NVIC base address */
#define    NVIC_BASE             0xE000E100UL

/* NVIC ISER0 register */
#define    NVIC_ISER0            (*(volatile uint32_t *)(NVIC_BASE))

/* SysTick registers */
#define    SYST_BASE             0xE000E010UL

#define    SYST_CSR              (*(volatile uint32_t *)(SYST_BASE + 0x00UL))
#define    SYST_RVR              (*(volatile uint32_t *)(SYST_BASE + 0x04UL))
#define    SYST_CVR              (*(volatile uint32_t *)(SYST_BASE + 0x08UL))
#define    SYST_CALIB            (*(volatile uint32_t *)(SYST_BASE + 0x0CUL))

#endif  /* STM32F407XX_REG_H */
