/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03_modified.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_EventTrigger_Cell_Info_Item_Choice_Individual_H_
#define	_EventTrigger_Cell_Info_Item_Choice_Individual_H_


#include <asn_application.h>

/* Including external dependencies */
#include "CGI.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* EventTrigger-Cell-Info-Item-Choice-Individual */
typedef struct EventTrigger_Cell_Info_Item_Choice_Individual {
	CGI_t	 cellGlobalID;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} EventTrigger_Cell_Info_Item_Choice_Individual_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EventTrigger_Cell_Info_Item_Choice_Individual;
extern asn_SEQUENCE_specifics_t asn_SPC_EventTrigger_Cell_Info_Item_Choice_Individual_specs_1;
extern asn_TYPE_member_t asn_MBR_EventTrigger_Cell_Info_Item_Choice_Individual_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _EventTrigger_Cell_Info_Item_Choice_Individual_H_ */
#include <asn_internal.h>
