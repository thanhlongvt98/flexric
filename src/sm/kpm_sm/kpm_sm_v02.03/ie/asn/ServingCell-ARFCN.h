/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "e2sm_kpm_v02.03_modified.asn1"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps -D asn`
 */

#ifndef	_ServingCell_ARFCN_H_
#define	_ServingCell_ARFCN_H_


#include <asn_application.h>

/* Including external dependencies */
#include "E-UTRA-ARFCN.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ServingCell_ARFCN_PR {
	ServingCell_ARFCN_PR_NOTHING,	/* No components present */
	ServingCell_ARFCN_PR_nR,
	ServingCell_ARFCN_PR_eUTRA
	/* Extensions may appear below */
	
} ServingCell_ARFCN_PR;

/* Forward declarations */
struct NR_ARFCN;

/* ServingCell-ARFCN */
typedef struct ServingCell_ARFCN {
	ServingCell_ARFCN_PR present;
	union ServingCell_ARFCN_u {
		struct NR_ARFCN	*nR;
		E_UTRA_ARFCN_t	 eUTRA;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ServingCell_ARFCN_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ServingCell_ARFCN;

#ifdef __cplusplus
}
#endif

#endif	/* _ServingCell_ARFCN_H_ */
#include <asn_internal.h>
