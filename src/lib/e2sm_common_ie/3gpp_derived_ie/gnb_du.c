#include <assert.h>
#include <stdlib.h>

#include "gnb_du.h"

void free_gnb_du_ue_id(gnb_du_t * src)
{
    assert(src != NULL);

    if (src->ran_ue_id != NULL)
        free(src->ran_ue_id);

}

bool eq_gnb_du_ue_id(gnb_du_t const * m0, gnb_du_t const * m1)
{
    assert(m0 != NULL);
    assert(m1 != NULL);

    // gNB DU UE F1AP
    if (m0->gnb_cu_ue_f1ap != m1->gnb_cu_ue_f1ap)
      return false;

    // RAN UE ID
    if (*m0->ran_ue_id != *m1->ran_ue_id)
      return false;

    return true;
}