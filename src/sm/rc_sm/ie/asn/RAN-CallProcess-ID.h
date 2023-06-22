/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03_modified.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_RAN_CallProcess_ID_H_
#define	_RAN_CallProcess_ID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RAN-CallProcess-ID */
typedef unsigned long	 RAN_CallProcess_ID_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_RAN_CallProcess_ID_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_RAN_CallProcess_ID;
extern const asn_INTEGER_specifics_t asn_SPC_RAN_CallProcess_ID_specs_1;
asn_struct_free_f RAN_CallProcess_ID_free;
asn_struct_print_f RAN_CallProcess_ID_print;
asn_constr_check_f RAN_CallProcess_ID_constraint;
ber_type_decoder_f RAN_CallProcess_ID_decode_ber;
der_type_encoder_f RAN_CallProcess_ID_encode_der;
xer_type_decoder_f RAN_CallProcess_ID_decode_xer;
xer_type_encoder_f RAN_CallProcess_ID_encode_xer;
jer_type_encoder_f RAN_CallProcess_ID_encode_jer;
per_type_decoder_f RAN_CallProcess_ID_decode_uper;
per_type_encoder_f RAN_CallProcess_ID_encode_uper;
per_type_decoder_f RAN_CallProcess_ID_decode_aper;
per_type_encoder_f RAN_CallProcess_ID_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RAN_CallProcess_ID_H_ */
#include <asn_internal.h>
