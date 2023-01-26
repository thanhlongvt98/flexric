#include <assert.h>

#include "dec_ric_action_def_frm_2.h"
#include "dec_ric_action_def_frm_1.h"


kpm_act_def_format_2_t kpm_dec_action_def_frm_2_asn(const E2SM_KPM_ActionDefinition_Format2_t * act_def_asn)
{
    kpm_act_def_format_2_t act_def={0};

    // UE_id

    act_def.action_def_format_1 = kpm_dec_action_def_frm_1_asn(&act_def_asn->subscriptInfo);

    return act_def;
}