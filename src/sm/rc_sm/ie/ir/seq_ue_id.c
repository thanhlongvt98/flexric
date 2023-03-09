#include "seq_ue_id.h"

#include <assert.h>

void free_seq_ue_id(seq_ue_id_t* src)
{
  assert(src != NULL);

  // UE ID
  // Mandatory
  // 9.3.10
  free_ue_id(&src->ue_id);

  // Sequence of
  // RAN Parameter
  // [1- 65535]
  assert(src->sz_seq_ran_param > 0 &&  src->sz_seq_ran_param < 65535+1);
  for(size_t i = 0; i < src->sz_seq_ran_param; ++i){
    free_seq_ran_param(&src->seq_ran_param[i]);
  }
  assert(src->seq_ran_param != NULL);
  free(src->seq_ran_param);

}

bool eq_seq_ue_id(seq_ue_id_t const* m0, seq_ue_id_t const* m1)
{
  if(m0 == m1)
    return true;

  if(m0 == NULL || m1 == NULL)
    return false;

  // UE ID
  // Mandatory
  // 9.3.10
  if(eq_ue_id(&m0->ue_id, &m1->ue_id) == false)
    return false;

  // Sequence of
  // RAN Parameter
  // [1- 65535]
  assert(m0->sz_seq_ran_param > 0 && m0->sz_seq_ran_param <  65535+1);
  assert(m1->sz_seq_ran_param > 0 && m1->sz_seq_ran_param <  65535+1);

  for(size_t i = 0; i < m0->sz_seq_ran_param; ++i){
    if(eq_seq_ran_param(&m0->seq_ran_param[i], &m1->seq_ran_param[i]) == false)
      return false;
  }

  return true;
}

