/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-CommonDataTypes"
 * 	found in "e2ap-v02.03.asn1"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_ProcedureCode_H_
#define	_ProcedureCode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ProcedureCode */
typedef long	 ProcedureCode_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ProcedureCode_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ProcedureCode;
asn_struct_free_f ProcedureCode_free;
asn_struct_print_f ProcedureCode_print;
asn_constr_check_f ProcedureCode_constraint;
ber_type_decoder_f ProcedureCode_decode_ber;
der_type_encoder_f ProcedureCode_encode_der;
xer_type_decoder_f ProcedureCode_decode_xer;
xer_type_encoder_f ProcedureCode_encode_xer;
per_type_decoder_f ProcedureCode_decode_uper;
per_type_encoder_f ProcedureCode_encode_uper;
per_type_decoder_f ProcedureCode_decode_aper;
per_type_encoder_f ProcedureCode_encode_aper;
#define ProcedureCode_id_E2setup	((ProcedureCode_t)1)
#define ProcedureCode_id_ErrorIndication	((ProcedureCode_t)2)
#define ProcedureCode_id_Reset	((ProcedureCode_t)3)
#define ProcedureCode_id_RICcontrol	((ProcedureCode_t)4)
#define ProcedureCode_id_RICindication	((ProcedureCode_t)5)
#define ProcedureCode_id_RICserviceQuery	((ProcedureCode_t)6)
#define ProcedureCode_id_RICserviceUpdate	((ProcedureCode_t)7)
#define ProcedureCode_id_RICsubscription	((ProcedureCode_t)8)
#define ProcedureCode_id_RICsubscriptionDelete	((ProcedureCode_t)9)
#define ProcedureCode_id_E2nodeConfigurationUpdate	((ProcedureCode_t)10)
#define ProcedureCode_id_E2connectionUpdate	((ProcedureCode_t)11)
#define ProcedureCode_id_RICsubscriptionDeleteRequired	((ProcedureCode_t)12)
#define ProcedureCode_id_E2removal	((ProcedureCode_t)13)

#ifdef __cplusplus
}
#endif

#endif	/* _ProcedureCode_H_ */
#include <asn_internal.h>
