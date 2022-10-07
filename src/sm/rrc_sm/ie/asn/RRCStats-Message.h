/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RRCStats-IEs"
 * 	found in "../e2sm_rrc_v00.asn"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_RRCStats_Message_H_
#define	_RRCStats_Message_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RRCUeStats;

/* RRCStats-Message */
typedef struct RRCStats_Message {
	struct RRCStats_Message__ueStats {
		A_SEQUENCE_OF(struct RRCUeStats) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ueStats;
	long	 tstamp;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RRCStats_Message_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RRCStats_Message;
extern asn_SEQUENCE_specifics_t asn_SPC_RRCStats_Message_specs_1;
extern asn_TYPE_member_t asn_MBR_RRCStats_Message_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _RRCStats_Message_H_ */
#include <asn_internal.h>
