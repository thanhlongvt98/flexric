#ifndef GLOBAL_NG_ENB_ID_H
#define GLOBAL_NG_ENB_ID_H

#ifdef __cplusplus
extern "C" {
#endif

#include "plmn_identity.h"

//  6.2.3.8 Global ng-eNB ID


typedef enum {
    MACRO_NG_ENB_TYPE_ID,
    SHORT_MACRO_NG_ENB_TYPE_ID,
    LONG_MACRO_NG_ENB_TYPE_ID,

    END_NG_ENB_TYPE_ID

} ng_enb_type_id_e;


typedef struct {
    plmn_t plmn_id;

    ng_enb_type_id_e type;
    union {
        uint8_t  macro_ng_enb_id[3];
        uint8_t  short_macro_ng_enb_id[3];
        uint8_t  long_macro_ng_enb_id[3];
    };

} global_ng_enb_id_t;

#ifdef __cplusplus
}
#endif

#endif

// done