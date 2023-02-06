#include <assert.h>
#include "../../ie/asn/asn_constant.h"

#include "dec_meas_info_frm_3.h"
#include "../../ie/asn/MeasurementCondItem.h"
#include "dec_matching_cond_frm_3.h"

meas_info_format_3_lst_t * kpm_dec_meas_info_cond_asn(const MeasurementCondList_t * meas_info_cond_asn, const size_t meas_info_cond_len)
{
    meas_info_format_3_lst_t * meas_info_cond = calloc(1,sizeof(meas_info_format_3_lst_t));
    assert(meas_info_cond != NULL && "Memory exhausted");

    for (size_t i = 0; i<meas_info_cond_len; i++)
    {
        const MeasurementType_t * meas_type_asn = &meas_info_cond_asn->list.array[i]->measType;
        assert(meas_type_asn->present == MeasurementType_PR_measName || meas_type_asn->present == MeasurementType_PR_measID);

        switch (meas_type_asn->present)
        {
        case MeasurementType_PR_measName:
            meas_info_cond[i].meas_type.type = NAME_MEAS_TYPE;
            meas_info_cond[i].meas_type.name.buf = calloc(meas_type_asn->choice.measName.size + 1, sizeof(char));
            assert(meas_info_cond[i].meas_type.name.buf != NULL && "Memory exhausted");
            memcpy(meas_info_cond[i].meas_type.name.buf, meas_type_asn->choice.measName.buf, meas_type_asn->choice.measName.size);
            meas_info_cond[i].meas_type.name.len = meas_type_asn->choice.measName.size;
            break;
        
        case MeasurementType_PR_measID:
            meas_info_cond[i].meas_type.type = ID_MEAS_TYPE;
            meas_info_cond[i].meas_type.id = meas_type_asn->choice.measID;
            break;

        }


        meas_info_cond[i].matching_cond_lst_len = meas_info_cond_asn->list.array[i]->matchingCond.list.count;
        assert(meas_info_cond[i].matching_cond_lst_len <= maxnoofConditionInfo && meas_info_cond[i].matching_cond_lst_len >= 1);

        for (size_t j = 0; j<meas_info_cond[i].matching_cond_lst_len; j++)
        {

            meas_info_cond[i].matching_cond_lst[j] = kpm_dec_matching_cond_asn(&meas_info_cond_asn->list.array[i]->matchingCond.list.array[j]);

        }

        // Bin Range Definition not yet implemented

    }

    return &meas_info_cond;
}