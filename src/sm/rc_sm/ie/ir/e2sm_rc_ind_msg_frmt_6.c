#include "e2sm_rc_ind_msg_frmt_6.h"

#include <assert.h>
#include <stdlib.h>

void free_e2sm_rc_ind_msg_frmt_6(e2sm_rc_ind_msg_frmt_6_t* src)
{
  assert(src != NULL);

  // Sequence of Insert Styles for Multiple Actions
  // [1-63]
  assert(src->sz_seq_ins_style_ind_msg > 0 && src->sz_seq_ins_style_ind_msg < 64); 

  for(size_t i = 0; i < src->sz_seq_ins_style_ind_msg; ++i){
    free_seq_ins_style_2(&src->seq_ins_style[i]);
  }

  assert(src->seq_ins_style != NULL);
  free(src->seq_ins_style);
}


bool eq_e2sm_rc_ind_msg_frmt_6( e2sm_rc_ind_msg_frmt_6_t const* m0, e2sm_rc_ind_msg_frmt_6_t const* m1)
{
  if(m0 == m1)
    return true;

  if(m0 == NULL || m1 == NULL)
    return false;
  
  // Sequence of Insert Styles for Multiple Actions
  // [1-63]
  assert(m0->sz_seq_ins_style_ind_msg > 0 && m0->sz_seq_ins_style_ind_msg < 64); 
  assert(m1->sz_seq_ins_style_ind_msg > 0 && m1->sz_seq_ins_style_ind_msg < 64); 

  if(m0->sz_seq_ins_style_ind_msg != m1->sz_seq_ins_style_ind_msg)
    return false;

  for(size_t i = 0; i < m0->sz_seq_ins_style_ind_msg; ++i){
    if(eq_seq_ins_style_2(&m0->seq_ins_style[i], &m1->seq_ins_style[i]) == false)
      return false;
  }

  return true;
}
