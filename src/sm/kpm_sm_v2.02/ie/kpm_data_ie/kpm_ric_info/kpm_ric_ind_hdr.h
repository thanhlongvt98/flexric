#ifndef RIC_INDICATION_HEADER_KPM_V2_H
#define RIC_INDICATION_HEADER_KPM_V2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "kpm_ric_ind_hdr_frm_1.h"


typedef enum {
  FORMAT_1_INDICATION_HEADER = 1,

  END_INDICATION_HEADER

} format_ind_hdr_e;


// 8.2.1.3    RIC INDICATION HEADER IE

typedef struct {
  format_ind_hdr_e type;
  union {
    kpm_ric_ind_hdr_format_1_t kpm_ric_ind_hdr_format_1;
  };
  

} kpm_ind_hdr_t;


#ifdef __cplusplus
}
#endif

#endif

// done