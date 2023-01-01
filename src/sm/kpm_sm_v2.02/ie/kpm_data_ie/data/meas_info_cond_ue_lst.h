#ifndef MEASUREMENT_INFORMATION_CONDITION_UE_LIST_KPM_V2_H
#define MEASUREMENT_INFORMATION_CONDITION_UE_LIST_KPM_V2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "matching_cond_frm_3_lst.h"
#include "../../../../lib/e2sm_common_ie/sm_common_ie/ue_id.h"
#include "ue_id_gran_period_lst.h"
#include "meas_type.h"

/* Intermediate structure for  8.2.1.4.2  E2SM-KPM Indication Message Format 2 */

typedef struct {
    meas_type_t meas_type;

    size_t matching_cond_lst_len;  // [1, 32768]
    matching_condition_format_3_lst_t *matching_cond_lst;

    size_t ue_id_matched_lst_len;  // [0, 65535]
    ue_id_t *ue_id_matched_lst;

    size_t ue_id_gran_period_lst_len;  // [0, 65535]
    ue_id_gran_period_lst_t *ue_id_gran_period_lst;


} meas_info_cond_ue_lst_t;


#ifdef __cplusplus
}
#endif

#endif

// done