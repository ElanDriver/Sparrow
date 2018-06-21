/*
 * drivers/input/touchscreen/ektf3xx/elan_ts.h
 * Elan Microelectronics touch panels with I2C interface
 *
 * Copyright (C) 2014 Elan Microelectronics Corporation.
 * Scott Liu <scott.liu@emc.com.tw>
 *
 */

/*
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 */

#ifndef _LINUX_ELAN_TS_H
#define _LINUX_ELAN_TS_H

/****************************customer info****************************/
#define ELAN_LCM_X	800
#define ELAN_LCM_Y	1280
#define ELAN_DEFAULT_X   1473
#define ELAN_DEFAULT_Y   2368
#define ELAN_ACTIVE_PEN_ID	0x07
#define ELAN_HAND_ID	0x62
#define ELAN_HID_HAND_ID	0x01
#define ELAN_BUF_SIZE	67
#define ELAN_DEFAULT_FINGER_COUNT 10
/****************************elan data info****************************/

/*i2c info*/
#define ELAN_TS_NAME "elan_ts"

#define ELAN_7BITS_ADDR 0x10
#define ELAN_8BITS_ADDR (ELAN_7BITS_ADDR<<1)
#define ELAN_I2C_TRAN
#define USE_THREAD
#define IAPRESTART 5

/*sleep  mode*/
#define PWR_STATE_DEEP_SLEEP	0
#define PWR_STATE_NORMAL		1
#define PWR_STATE_MASK		BIT(3)

/*cmd or paket head*/
#define CMD_S_PKT			0x52
#define CMD_R_PKT			0x53
#define CMD_W_PKT			0x54
#define HELLO_PKT			0x55
#define RAM_PKT				0xcc
#define BUFF_PKT			0x63

/*elan IC series(only choose one)*/
/*#define ELAN_2K_XX*/
#define ELAN_3K_XX
/*#define ELAN_RAM_XX*/

/**********************fingers number macro switch**********************/
/*#define ELAN_BUFFER_MODE*/
/*#define ELAN_ICS_SLOT_REPORT*/

/***********************debug info macro switch***********************/
#define PRINT_INT_INFO
#define DRV_VERSION "1.0.1"
/*************************have button macro switch*********************/
static const int key_value[] = {KEY_MENU, KEY_HOME, KEY_BACK};


#define  ELAN_KEY_BACK    0x02
#define  ELAN_KEY_MENU    0x01
#define  ELAN_KEY_NONE    0x00
#define  ELAN_KEY_HOME    0x03

/*************************dev file macro switch********************/
#define ELAN_IAP_DEV

#ifdef ELAN_IAP_DEV
/*For Firmware Update *****/
#define ELAN_IOCTLID	0xD0
#define IOCTL_I2C_SLAVE	_IOW(ELAN_IOCTLID,  1, int)
#define IOCTL_MAJOR_FW_VER  _IOR(ELAN_IOCTLID, 2, int)
#define IOCTL_MINOR_FW_VER  _IOR(ELAN_IOCTLID, 3, int)
#define IOCTL_RESET  _IOR(ELAN_IOCTLID, 4, int)
#define IOCTL_IAP_MODE_LOCK  _IOR(ELAN_IOCTLID, 5, int)
#define IOCTL_CHECK_RECOVERY_MODE  _IOR(ELAN_IOCTLID, 6, int)
#define IOCTL_FW_VER  _IOR(ELAN_IOCTLID, 7, int)
#define IOCTL_X_RESOLUTION  _IOR(ELAN_IOCTLID, 8, int)
#define IOCTL_Y_RESOLUTION  _IOR(ELAN_IOCTLID, 9, int)
#define IOCTL_FW_ID  _IOR(ELAN_IOCTLID, 10, int)
#define IOCTL_ROUGH_CALIBRATE  _IOR(ELAN_IOCTLID, 11, int)
#define IOCTL_IAP_MODE_UNLOCK  _IOR(ELAN_IOCTLID, 12, int)
#define IOCTL_I2C_INT  _IOR(ELAN_IOCTLID, 13, int)
#define IOCTL_RESUME  _IOR(ELAN_IOCTLID, 14, int)
#define IOCTL_POWER_LOCK  _IOR(ELAN_IOCTLID, 15, int)
#define IOCTL_POWER_UNLOCK  _IOR(ELAN_IOCTLID, 16, int)
#define IOCTL_FW_UPDATE  _IOR(ELAN_IOCTLID, 17, int)
#define IOCTL_BC_VER  _IOR(ELAN_IOCTLID, 18, int)
#define IOCTL_2WIREICE  _IOR(ELAN_IOCTLID, 19, int)
#define IOCTL_VIAROM	_IOR(ELAN_IOCTLID, 20, int)
#define IOCTL_VIAROM_CHECKSUM	_IOW(ELAN_IOCTLID, 21, unsigned long)

#define IOCTL_GET_UPDATE_PROGREE	_IOR(CUSTOMER_IOCTLID,  2, int)

#endif


/**********************update firmware macro switch*******************/
/*#define USE_128_MODE*/
#define IAP_PORTION

#if defined IAP_PORTION || defined ELAN_RAM_XX
	/*The newest firmware, if update must be changed here*/
/*	static uint8_t file_fw_data[] = {
		#include "fw_data.i"
	};
*/
	static uint8_t *file_fw_data_out;
#endif
	enum {
		PageSize = 132,
		ACK_Fail = 0x00,
		ACK_OK = 0xAA,
		ACK_REWRITE = 0x55,
		E_FD = -1,
	};

/**********************elan attr file macro switch*******************/
/*#define SYS_ATTR_FILE*/
#ifdef SYS_ATTR_FILE
	static struct kobject *android_touch_kobj;
#endif
#endif /* _LINUX_ELAN_TS_H */
#define SYS_DEFAULT_ATTR

