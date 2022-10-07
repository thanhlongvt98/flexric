/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RRCStats-IEs"
 * 	found in "../e2sm_rrc_v00.asn"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_RANparameter_Value_H_
#define	_RANparameter_Value_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RANparameter-Value */
typedef OCTET_STRING_t	 RANparameter_Value_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANparameter_Value;
asn_struct_free_f RANparameter_Value_free;
asn_struct_print_f RANparameter_Value_print;
asn_constr_check_f RANparameter_Value_constraint;
ber_type_decoder_f RANparameter_Value_decode_ber;
der_type_encoder_f RANparameter_Value_encode_der;
xer_type_decoder_f RANparameter_Value_decode_xer;
xer_type_encoder_f RANparameter_Value_encode_xer;
per_type_decoder_f RANparameter_Value_decode_uper;
per_type_encoder_f RANparameter_Value_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _RANparameter_Value_H_ */
#include <asn_internal.h>
