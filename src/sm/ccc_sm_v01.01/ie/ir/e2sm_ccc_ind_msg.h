#ifndef CELL_CONFIGURATION_AND_CONTROL_INDICATION_MESSAGE_SM_H
#define CELL_CONFIGURATION_AND_CONTROL_INDICATION_MESSAGE_SM_H

#include "e2sm_ccc_ind_msg_frm_1.h"
#include "e2sm_ccc_ind_msg_frm_2.h"

typedef enum {
    FORMAT_1_INDICATION_MESSAGE_CCC,
    FORMAT_2_INDICATION_MESSAGE_CCC,

    END_INDICATION_MESSAGE_CCC

} e2sm_ccc_ind_msg_e;


/* 9.2.1.4  RIC INDICATION MESSAGE IE  */

typedef struct {
    e2sm_ccc_ind_msg_e type;

    union {
        e2sm_ccc_ind_msg_frm_1_t frm_1;  // 9.2.1.4.1
        e2sm_ccc_ind_msg_frm_2_t frm_2;  // 9.2.1.4.2
    };

} e2sm_ccc_ind_msg_t;

#endif