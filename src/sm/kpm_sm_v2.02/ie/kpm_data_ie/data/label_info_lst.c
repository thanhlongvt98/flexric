#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "label_info_lst.h"

static long* dup_long(const long* src)
{
  if (src == NULL)
    return NULL;
  long* dst = malloc(sizeof(*dst));
  assert(dst != NULL && "memory exhausted");
  *dst = *src;
  return dst;
}

void cp_label_info(label_info_lst_t *dst, label_info_lst_t const *src) 
{
  assert(src != NULL);
  assert(dst != NULL);

  dst->noLabel = dup_long(src->noLabel);
  if (src->plmn_id != NULL) {
    dst->plmn_id = malloc(sizeof(*dst->plmn_id));
    *dst->plmn_id = *src->plmn_id;
  }

  // TO BE COMPLETED with the other fields
}

void free_label_info(label_info_lst_t *l) 
{
  assert(l != NULL);

  if (l->noLabel)
    free (l->noLabel);
  if (l->plmn_id)
    free(l->plmn_id);
 
  if (l->sliceID != NULL) {
    assert(false && "not implemented");
  }
	if (l->fiveQI != NULL) {
    assert(false && "not implemented");
  }
	if (l->qFI != NULL) {
    assert(false && "not implemented");
  }
	if (l->qCI != NULL) {
    assert(false && "not implemented");
  }
	if (l->qCImax != NULL) {
    assert(false && "not implemented");
  }
	if (l->qCImin != NULL) {
    assert(false && "not implemented");
  }
	if (l->aRPmax != NULL) {
    assert(false && "not implemented");
  }
	if (l->aRPmin != NULL) {
    assert(false && "not implemented");
  }
	if (l->bitrateRange != NULL) {
    assert(false && "not implemented");
  }
	if (l->layerMU_MIMO != NULL) {
    assert(false && "not implemented");
  }
	if (l->sUM != NULL) {
    assert(false && "not implemented");
  }
	if (l->distBinX != NULL) {
    assert(false && "not implemented");
  }
	if (l->distBinY != NULL) {
    assert(false && "not implemented");
  }
	if (l->distBinZ != NULL) {
    assert(false && "not implemented");
  }
	if (l->preLabelOverride != NULL) {
    assert(false && "not implemented");
  }
	if (l->startEndInd != NULL) {
    assert(false && "not implemented");
  }
	if (l->min != NULL) {
    assert(false && "not implemented");
  }
	if (l->max != NULL) {
    assert(false && "not implemented");
  }
	if (l->avg != NULL) {
    assert(false && "not implemented");
  }
}