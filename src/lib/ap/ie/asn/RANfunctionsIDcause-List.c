/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "e2ap-v02.03.asn1"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#include "RANfunctionsIDcause-List.h"

#include "ProtocolIE-SingleContainer.h"
asn_per_constraints_t asn_PER_type_RANfunctionsIDcause_List_constr_1 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 8,  8,  1,  256 }	/* (SIZE(1..256)) */,
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_RANfunctionsIDcause_List_1[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_ProtocolIE_SingleContainer_2156P16,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_RANfunctionsIDcause_List_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_SET_OF_specifics_t asn_SPC_RANfunctionsIDcause_List_specs_1 = {
	sizeof(struct RANfunctionsIDcause_List),
	offsetof(struct RANfunctionsIDcause_List, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
asn_TYPE_descriptor_t asn_DEF_RANfunctionsIDcause_List = {
	"RANfunctionsIDcause-List",
	"RANfunctionsIDcause-List",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_RANfunctionsIDcause_List_tags_1,
	sizeof(asn_DEF_RANfunctionsIDcause_List_tags_1)
		/sizeof(asn_DEF_RANfunctionsIDcause_List_tags_1[0]), /* 1 */
	asn_DEF_RANfunctionsIDcause_List_tags_1,	/* Same as above */
	sizeof(asn_DEF_RANfunctionsIDcause_List_tags_1)
		/sizeof(asn_DEF_RANfunctionsIDcause_List_tags_1[0]), /* 1 */
	{ 0, &asn_PER_type_RANfunctionsIDcause_List_constr_1, SEQUENCE_OF_constraint },
	asn_MBR_RANfunctionsIDcause_List_1,
	1,	/* Single element */
	&asn_SPC_RANfunctionsIDcause_List_specs_1	/* Additional specs */
};

