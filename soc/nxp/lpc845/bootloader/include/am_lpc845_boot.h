/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief bootloader drivers for standard interface
 *
 * \internal
 * \par Modification history
 * - 1.00 18-11-15  yrh, first implementation
 * \endinternal
 */

#ifndef __AM_lpc845_BOOT_H
#define __AM_lpc845_BOOT_H

#include "am_boot.h"
//#include "hw/amhw_lpc84x_iap.h"
#include "am_boot_flash.h"

typedef struct am_lpc845_boot_devinfo {
    uint32_t  app_start_addr;      /**< \brief Ӧ�ô�������ʼ��ַ*/
    uint32_t  update_flag_addr;    /**< \brief ������־�Ĵ�ŵ�ַ��һ���Ƿ���Ӧ�ô�������ʼ��ַ��ǰ4�ֽ�*/
    uint32_t  flash_start_addr;    /**< \brief flash����ʼ��ַ*/
    uint32_t  flash_size;          /**< \brief flash�Ĵ�С */

    uint32_t  update_start_addr;   /**< \brief Ӧ�ô��������������ݣ���ַ */
    uint32_t  ram_start_addr;      /**< \brief ram��ʼ��ַ */
    uint32_t  ram_size;            /**< \brief ram�Ĵ�С */

    void (*pfn_plfm_init)(void);   /**< \brief ƽ̨��ʼ������ */

    void (*pfn_plfm_deinit)(void); /**< \brief ƽ̨ȥ��ʼ������ */
}am_lpc845_boot_devinfo_t;

typedef struct am_lpc845_boot_dev {
    am_lpc845_boot_devinfo_t *p_devinfo;
    am_boot_flash_handle_t    flash_handle;   /**< \brief flash������� */

}am_lpc845_boot_dev_t;

/**
 * \brief ��ʼ��BootLoader������BootLoader��׼����������
 *
 * \param[in] p_dev     : ָ��BootLoader�豸��ָ��
 * \param[in] p_devinfo : ָ��BootLoader�豸��Ϣ������ָ��
 *
 * \return BootLoader��׼������������ֵΪNULLʱ������ʼ��ʧ��
 */
int am_lpc845_boot_init(am_lpc845_boot_dev_t      *p_dev,
                        am_lpc845_boot_devinfo_t  *p_devinfo,
                        am_boot_flash_handle_t     flash_handle);


#endif /* __AM_lpc845_BOOT_H */