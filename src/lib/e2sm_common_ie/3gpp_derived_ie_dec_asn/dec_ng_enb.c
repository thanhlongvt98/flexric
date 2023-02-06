#include <assert.h>

#include "../../../../util/conversions.h"

#include "dec_ng_enb.h"
#include "dec_global_ng_enb.h"
#include "dec_global_ng_ran.h"


ng_enb_t dec_ng_eNB_UE_asn(const UEID_NG_ENB_t * ng_enb_asn)
{
    ng_enb_t ng_enb = {0};


    // AMF UE NGAP ID
    ng_enb.amf_ue_ngap_id = ng_enb_asn->amf_UE_NGAP_ID;


    // GUAMI

    PLMNID_TO_MCC_MNC(&ng_enb_asn->guami.pLMNIdentity, ng_enb.guami.plmn_id.mcc, ng_enb.guami.plmn_id.mnc, ng_enb.guami.plmn_id.mnc_digit_len);

    OCTET_STRING_TO_INT8(&ng_enb_asn->guami.aMFRegionID, ng_enb.guami.amf_region_id);

    OCTET_STRING_TO_INT16(&ng_enb_asn->guami.aMFSetID, ng_enb.guami.amf_set_id);

    OCTET_STRING_TO_INT8(&ng_enb_asn->guami.aMFPointer, ng_enb.guami.amf_ptr);


    // C-if CU DU separated
    // ng-eNB-CU UE W1AP ID

    if (ng_enb_asn->ng_eNB_CU_UE_W1AP_ID != NULL)
    {
        ng_enb.ng_enb_cu_ue_w1ap_id = calloc(1, sizeof(*ng_enb.ng_enb_cu_ue_w1ap_id));
        ng_enb.ng_enb_cu_ue_w1ap_id = ng_enb_asn->ng_eNB_CU_UE_W1AP_ID;
    }


    // C- ifDCSetup
    // M-NG-RAN node UE XnAP ID

    if (ng_enb_asn->m_NG_RAN_UE_XnAP_ID != NULL)
    {
        ng_enb.ng_ran_node_ue_xnap_id = calloc(1, sizeof(*ng_enb.ng_ran_node_ue_xnap_id));
        ng_enb.ng_ran_node_ue_xnap_id = ng_enb_asn->m_NG_RAN_UE_XnAP_ID;
    }


    // Global NG eNB
    // Optional
    ng_enb.global_ng_enb_id = dec_global_ng_enb_asn(&ng_enb_asn->globalNgENB_ID);


    // Global NG-RAN Node ID
    // C-ifDCSetup
    ng_enb.global_ng_ran_node_id = dec_global_ng_ran_asn(&ng_enb_asn->globalNG_RANNode_ID);

    return ng_enb;
}