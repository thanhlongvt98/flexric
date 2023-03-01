#include <assert.h>

#include "kpm_ric_ind_msg_frm_3.h"

void free_kpm_ind_msg_frm_3(kpm_ind_msg_format_3_t * src)
{
  assert(src != NULL);

  for (size_t i = 0; i<src->ue_meas_report_lst_len; i++)
  {
    free_ue_id(&src->meas_report_per_ue[i].ue_meas_report_lst);
    free_kpm_ind_msg_frm_1(&src->meas_report_per_ue[i].ind_msg_format_1);
  }
  free(src->meas_report_per_ue);


}

bool eq_kpm_ind_msg_frm_3(kpm_ind_msg_format_3_t const * m0, kpm_ind_msg_format_3_t const * m1)
{
  assert(m0 != NULL);
  assert(m1 != NULL);

  if (m0->ue_meas_report_lst_len != m1->ue_meas_report_lst_len)
    return false;

  for (size_t i = 0; i<m0->ue_meas_report_lst_len; i++)
  {
    if(eq_ue_id(&m0->meas_report_per_ue[i].ue_meas_report_lst, &m1->meas_report_per_ue[i].ue_meas_report_lst) != true)
      return false;

    if (eq_kpm_ind_msg_frm_1(&m0->meas_report_per_ue[i].ind_msg_format_1, &m1->meas_report_per_ue[i].ind_msg_format_1) != true)
      return false;
  }


  return true;
}