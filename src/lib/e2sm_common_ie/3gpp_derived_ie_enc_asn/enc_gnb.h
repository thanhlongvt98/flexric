#ifndef ENCRYPTION_GNB_H
#define ENCRYPTION_GNB_H


#ifdef __cplusplus
extern "C" {
#endif

#include "../../../sm/kpm_sm_v2.02/ie/asn/UEID-GNB.h"
#include "../3gpp_derived_ie/gnb.h"

UEID_GNB_t * enc_gNB_UE_asn(const gnb_t * gnb);

#ifdef __cplusplus
}
#endif

#endif