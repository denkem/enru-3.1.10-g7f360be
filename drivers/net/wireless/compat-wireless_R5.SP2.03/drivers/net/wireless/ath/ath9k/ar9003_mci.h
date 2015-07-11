/*
 * Copyright (c) 2010-2011 Atheros Communications Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef AR9003_MCI_H
#define AR9003_MCI_H

#define MCI_FLAG_DISABLE_TIMESTAMP      0x00000001      /* Disable time stamp */

/* Default remote BT device MCI COEX version */
#define MCI_GPM_COEX_MAJOR_VERSION_DEFAULT  3
#define MCI_GPM_COEX_MINOR_VERSION_DEFAULT  0

/* Local WLAN MCI COEX version */
#define MCI_GPM_COEX_MAJOR_VERSION_WLAN     3
#define MCI_GPM_COEX_MINOR_VERSION_WLAN     0

enum mci_gpm_coex_query_type {
	MCI_GPM_COEX_QUERY_BT_ALL_INFO      = BIT(0),
	MCI_GPM_COEX_QUERY_BT_TOPOLOGY      = BIT(1),
	MCI_GPM_COEX_QUERY_BT_DEBUG         = BIT(2),
};

enum mci_gpm_coex_halt_bt_gpm {
	MCI_GPM_COEX_BT_GPM_UNHALT,
	MCI_GPM_COEX_BT_GPM_HALT
};

enum mci_gpm_coex_bt_update_flags_op {
	MCI_GPM_COEX_BT_FLAGS_READ,
	MCI_GPM_COEX_BT_FLAGS_SET,
	MCI_GPM_COEX_BT_FLAGS_CLEAR
};

#define MCI_NUM_BT_CHANNELS     79

#define MCI_BT_MCI_FLAGS_UPDATE_CORR          0x00000002
#define MCI_BT_MCI_FLAGS_UPDATE_HDR           0x00000004
#define MCI_BT_MCI_FLAGS_UPDATE_PLD           0x00000008
#define MCI_BT_MCI_FLAGS_LNA_CTRL             0x00000010
#define MCI_BT_MCI_FLAGS_DEBUG                0x00000020
#define MCI_BT_MCI_FLAGS_SCHED_MSG            0x00000040
#define MCI_BT_MCI_FLAGS_CONT_MSG             0x00000080
#define MCI_BT_MCI_FLAGS_COEX_GPM             0x00000100
#define MCI_BT_MCI_FLAGS_CPU_INT_MSG          0x00000200
#define MCI_BT_MCI_FLAGS_MCI_MODE             0x00000400
#define MCI_BT_MCI_FLAGS_AR9462_MODE          0x00001000
#define MCI_BT_MCI_FLAGS_OTHER                0x00010000

#define MCI_DEFAULT_BT_MCI_FLAGS              0x00011dde

#define MCI_TOGGLE_BT_MCI_FLAGS  (MCI_BT_MCI_FLAGS_UPDATE_CORR | \
				  MCI_BT_MCI_FLAGS_UPDATE_HDR  | \
				  MCI_BT_MCI_FLAGS_UPDATE_PLD  | \
				  MCI_BT_MCI_FLAGS_MCI_MODE)

#define MCI_2G_FLAGS_CLEAR_MASK   0x00000000
#define MCI_2G_FLAGS_SET_MASK     MCI_TOGGLE_BT_MCI_FLAGS
#define MCI_2G_FLAGS              MCI_DEFAULT_BT_MCI_FLAGS

#define MCI_5G_FLAGS_CLEAR_MASK   MCI_TOGGLE_BT_MCI_FLAGS
#define MCI_5G_FLAGS_SET_MASK     0x00000000
#define MCI_5G_FLAGS              (MCI_DEFAULT_BT_MCI_FLAGS & \
				   ~MCI_TOGGLE_BT_MCI_FLAGS)

/*
 * Default value for AR9462 is 0x00002201
 */
#define ATH_MCI_CONFIG_CONCUR_TX            0x00000003
#define ATH_MCI_CONFIG_MCI_OBS_MCI          0x00000004
#define ATH_MCI_CONFIG_MCI_OBS_TXRX         0x00000008
#define ATH_MCI_CONFIG_MCI_OBS_BT           0x00000010
#define ATH_MCI_CONFIG_DISABLE_MCI_CAL      0x00000020
#define ATH_MCI_CONFIG_DISABLE_OSLA         0x00000040
#define ATH_MCI_CONFIG_DISABLE_FTP_STOMP    0x00000080
#define ATH_MCI_CONFIG_AGGR_THRESH          0x00000700
#define ATH_MCI_CONFIG_AGGR_THRESH_S        8
#define ATH_MCI_CONFIG_DISABLE_AGGR_THRESH  0x00000800
#define ATH_MCI_CONFIG_CLK_DIV              0x00003000
#define ATH_MCI_CONFIG_CLK_DIV_S            12
#define ATH_MCI_CONFIG_DISABLE_TUNING       0x00004000
#define ATH_MCI_CONFIG_MCI_WEIGHT_DBG       0x40000000
#define ATH_MCI_CONFIG_DISABLE_MCI          0x80000000

#define ATH_MCI_CONFIG_MCI_OBS_MASK     (ATH_MCI_CONFIG_MCI_OBS_MCI  | \
					 ATH_MCI_CONFIG_MCI_OBS_TXRX | \
					 ATH_MCI_CONFIG_MCI_OBS_BT)
#define ATH_MCI_CONFIG_MCI_OBS_GPIO     0x0000002F

#endif
