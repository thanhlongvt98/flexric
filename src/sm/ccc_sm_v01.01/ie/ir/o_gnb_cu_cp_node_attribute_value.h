#ifndef O_GNB_CU_CP_NODE_ATTRIBUTE_VALUE_H
#define O_GNB_CU_CP_NODE_ATTRIBUTE_VALUE_H

#include <stdint.h>

#include "../../../../util/byte_array.h"
#include "../../../../lib/e2sm_common_ie/3gpp_derived_ie/plmn_identity.h"


// 8.8.1.2  O-GNBCUCPFunction - REPORT & CONTROL services

typedef union {
    const uint32_t gnb_id;  // It identifies a gNB within a PLMN. The gNB ID is part of the NR Cell Identifier (NCI) of the gNB cells. See "gNB Identifier (gNB ID)" of subclause 8.2 of TS 38.300 [3]. 
    const uint8_t gnb_id_length:5;  // This indicates the number of bits for encoding the gNB ID. See "Global gNB ID" in subclause 9.3.1.6 of TS 38.413 [5].
    const byte_array_t gnb_cu_name;  //  It identifies the Central Entity of a NR node, see subclause 9.2.1.4 of 3GPP TS 38.473 [8].
    const plmn_t plmn_id;  //  9.3.12  It specifies the PLMN identifier to be used as part of the global RAN node identity.
    byte_array_t x2_exclude_list;  //  x2BlockList; This is a list of GeNBIds. 
    byte_array_t x2_include_list;  //  x2AllowList; This is a list of GeNBIds. 
    byte_array_t xn_exclude_list;  //  xnBlockList; This is a list of GgNBIds. 
    byte_array_t xn_include_list;  //  xnAllowList; This is a list of GgNBIds. 
    byte_array_t x2_ho_exclude_list;  //  x2HOBlockList
    byte_array_t xn_ho_exclude_list;  //  xnHOBlockList

} o_gnb_cu_cp_node_attribute_value_u;  //  for indication message

#endif