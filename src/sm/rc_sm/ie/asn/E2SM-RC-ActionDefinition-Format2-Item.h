/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03_modified.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_E2SM_RC_ActionDefinition_Format2_Item_H_
#define	_E2SM_RC_ActionDefinition_Format2_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RIC-PolicyAction.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RANParameter_Testing;

/* E2SM-RC-ActionDefinition-Format2-Item */
typedef struct E2SM_RC_ActionDefinition_Format2_Item {
	RIC_PolicyAction_t	 ric_PolicyAction;
	struct RANParameter_Testing	*ric_PolicyConditionDefinition;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_ActionDefinition_Format2_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_ActionDefinition_Format2_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_ActionDefinition_Format2_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_RC_ActionDefinition_Format2_Item_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_ActionDefinition_Format2_Item_H_ */
#include <asn_internal.h>
